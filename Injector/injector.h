#pragma once
#include <Windows.h>
#include <string>
#include <memory>



    bool LaunchAndInject(const std::string& exePath, const std::string& dllPath, const std::string& cmdArgs = "");

