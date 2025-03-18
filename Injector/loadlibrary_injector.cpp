#include "loadlibrary_injector.h"
#include <iostream>

bool Inject(HANDLE hTarget, const char* dllpath) {
    LPVOID loadlib = GetProcAddress(GetModuleHandle(L"kernel32"), "LoadLibraryA");
    LPVOID dllPathAddr = VirtualAllocEx(hTarget, nullptr, strlen(dllpath) + 1, MEM_COMMIT | MEM_RESERVE,
                                        PAGE_READWRITE);

    if (dllPathAddr == nullptr) {
        std::cout << "Failed allocating memory in the target process. GetLastError(): " << GetLastError() << "\n";
        return false;
    }

    if (!WriteProcessMemory(hTarget, dllPathAddr, dllpath, strlen(dllpath) + 1, nullptr)) {
        std::cout << "Failed writing to process. GetLastError(): " << GetLastError() << "\n";
        return false;
    }

    HANDLE hThread = CreateRemoteThread(hTarget, nullptr, NULL, (LPTHREAD_START_ROUTINE) loadlib, dllPathAddr, NULL,
                                        nullptr);

    if (hThread == nullptr) {
        std::cout << "Failed to create a thread in the target process. GetLastError(): " << GetLastError() << "\n";
        return false;
    }

    WaitForSingleObject(hThread, INFINITE);

    DWORD exit_code = 0;
    
    GetExitCodeThread(hThread, &exit_code);
    VirtualFreeEx(hTarget, dllPathAddr, 0, MEM_RELEASE);
    CloseHandle(hThread);

    if (exit_code == 0) {
        std::cout << "LoadLibrary failed with exit code 0.\n";
        return false;
    }
    return true;
}
