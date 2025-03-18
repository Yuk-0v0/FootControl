#pragma once
#include <Windows.h>
#include	<string>

bool Inject(HANDLE processHandle, const char* dllPath);