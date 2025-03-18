#include "config.h"
#include <Windows.h>
#include <filesystem>

namespace fs = std::filesystem;

static std::string GetIniPath() {
    char exePath[MAX_PATH];
    GetModuleFileNameA(nullptr, exePath, MAX_PATH);
    fs::path path(exePath);
    path.replace_filename("config.ini");
    return path.string();
}

Config LoadConfig() {
    Config config;
    const std::string iniPath = GetIniPath();
    char buffer[MAX_PATH] = { 0 };

    GetPrivateProfileStringA("Paths", "ExePath", "", buffer, MAX_PATH, iniPath.c_str());
    config.exePath = buffer;

    GetPrivateProfileStringA("Paths", "DllPath", "", buffer, MAX_PATH, iniPath.c_str());
    config.dllPath = buffer;

    GetPrivateProfileStringA("Paths", "CmdArgs", "", buffer, MAX_PATH, iniPath.c_str());
    config.cmdArgs = buffer;

    return config;
}

void SaveDefaultConfig(const Config& config) {
    const std::string iniPath = GetIniPath();

    WritePrivateProfileStringA("Paths", "ExePath", config.exePath.c_str(), iniPath.c_str());
    WritePrivateProfileStringA("Paths", "DllPath", config.dllPath.c_str(), iniPath.c_str());
    WritePrivateProfileStringA("Paths", "CmdArgs", config.cmdArgs.c_str(), iniPath.c_str());
}