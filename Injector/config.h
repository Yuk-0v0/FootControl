#pragma once
#include <string>

struct Config {
    std::string exePath;
    std::string dllPath;
    std::string cmdArgs;
};

Config LoadConfig();
void SaveDefaultConfig(const Config& config);