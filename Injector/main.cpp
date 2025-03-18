#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <memory>
#include <string>
#include <commdlg.h> // For common dialogs
#include "injector.h"
#include "loadlibrary_injector.h"
#include "resource.h"
#include "config.h"

#pragma comment(lib, "Comdlg32.lib") // Link with the Common Dialog Box Library

// Helper function to open a file dialog
std::wstring OpenFileDialog(const wchar_t* filter, const wchar_t* title) {
    OPENFILENAMEW ofn;
    wchar_t szFile[260] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = nullptr; // If you have a window handle, use it here
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile) / sizeof(wchar_t);
    ofn.lpstrFilter = filter;
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = nullptr;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = nullptr;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    ofn.lpstrTitle = title;

    if (GetOpenFileNameW(&ofn) == TRUE) {
        return std::wstring(szFile);
    }
    return L""; // Return empty string if no file is selected
}

int main() {
    Config config = LoadConfig();

    // 如果配置文件不存在或路径为空，使用默认值并保存
    if (config.exePath.empty() || config.dllPath.empty()) {
        std::cout << "Config file not found or paths are empty, prompting for file selection...\n";

        // Prompt for EXE file
        std::wstring exePathW = OpenFileDialog(L"Executable Files (*.exe)\0*.exe\0All Files (*.*)\0*.*\0", L"Select EXE File");
        if (!exePathW.empty()) {
            config.exePath = std::filesystem::absolute(exePathW).string();
        }
        else {
            std::cout << "No EXE file selected. Exiting...\n";
            system("pause");
            return 1;
        }

        // Prompt for DLL file
        std::wstring dllPathW = OpenFileDialog(L"DLL Files (*.dll)\0*.dll\0All Files (*.*)\0*.*\0", L"Select DLL File");
        if (!dllPathW.empty()) {
            config.dllPath = std::filesystem::absolute(dllPathW).string();
        }
        else {
            std::cout << "No DLL file selected. Exiting...\n";
            system("pause");
            return 1;
        }

        config.cmdArgs = ""; // Set default for command line arguments
        SaveDefaultConfig(config);
    }

    std::cout << "Using configuration:\n"
        << "EXE Path: " << config.exePath << "\n"
        << "DLL Path: " << config.dllPath << "\n"
        << "Arguments: " << (config.cmdArgs.empty() ? "" : config.cmdArgs) << "\n";

    std::cout << "Starting injection process...\n";
    if (!LaunchAndInject(config.exePath, config.dllPath, config.cmdArgs)) {
        std::cout << "Injection process failed\n";
        system("pause");
        return 1;
    }

    std::cout << "Process completed successfully\n";
    return 0;
}