#include <Windows.h>
#include <iostream>
#include "injector.h"
#include "loadlibrary_injector.h"


bool LaunchAndInject(const std::string& exePath, const std::string& dllPath, const std::string& cmdArgs) {
    STARTUPINFOA si{};
    PROCESS_INFORMATION pi{};
    //si.cb = sizeof(si);

    // 创建完整的命令行，包含可执行文件路径和额外的命令行参数
    std::string fullCmdLine = exePath;
    if (!cmdArgs.empty()) {
        fullCmdLine += " " + cmdArgs;
    }
   

    printf("exePath: %s\n", exePath.c_str());
    printf("dllPath: %s\n", dllPath.c_str());
    printf("Launching: %s\n", fullCmdLine.c_str());
    // 创建进程（suspended状态）
    if (!CreateProcessA(nullptr, const_cast<char*>(fullCmdLine.c_str()), nullptr, nullptr, FALSE,
        0,
                       nullptr, nullptr, &si, &pi)) {
        std::cout << "Failed to create process. Error: " << GetLastError() << "\n";
       // free(cmdLine);
        return false;
    }
    
    //free(cmdLine);

    
    // 使用指定方法注入DLL
   // Sleep(3000);
    bool success = Inject(pi.hProcess, dllPath.c_str());
    //bool success = true;
    if (success) {
        std::cout << "DLL injection successful\n";
        ResumeThread(pi.hThread);
    } else {
        std::cout << "DLL injection failed\n";
        TerminateProcess(pi.hProcess, 1);
    }

    // 清理
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    
    return success;
}

