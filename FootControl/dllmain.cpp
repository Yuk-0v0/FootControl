#include "api/directx/D3D11Hook.hpp"
#include "il2cpp/il2cpp-init.hpp"

#include "includes.h"
#include "api/json/json.hpp"
using json = nlohmann::json;
bool proxy = false;
std::string proxyhost = "";

#include "functions/Settings/Settings.h"
static app::String* WebRequestUtils_MakeInitialUrl_Hook(app::String* targetUrl, app::String* localUrl, app::MethodInfo* method);
app::String* UnityWebRequest_get_url_Hook (void/*app::UnityWebRequest*/* __this, app::MethodInfo* method);

static void get_proxy() {
    std::ifstream file("FootControl.json");
    if (!file.is_open()) {
        // std::cerr << "无法打开 FootControl.json 文件" << std::endl;
        return;
    }

    json data;
    try {
        file >> data;
    }
    catch (json::parse_error& e) {
        // 处理 JSON 解析错误，例如文件格式错误
        // std::cerr << "JSON 解析错误: " << e.what() << std::endl;
        return;
    }

    if (data.contains("functions") && data["functions"].contains("Debug")) {
        auto debug = data["functions"]["Debug"];
        if (debug.contains("Proxyhost") && debug.contains("Proxy")) {
            proxyhost = debug["Proxyhost"];
            proxy = debug["Proxy"];
        }
        else {
            //缺少proxyhost或者proxy，直接返回
            return;
        }

    }
    else {
        // 如果找不到 "functions" 或 "Debug" 键，直接返回
        return;
    }
}
app::String* WebRequestUtils_MakeInitialUrl_Hook(app::String* targetUrl, app::String* localUrl, app::MethodInfo* method) {
    LOG_DEBUG("WebRequestUtils_MakeInitialUrl_Hook targetUrl: %s", il2cppi_to_string(targetUrl).c_str());
    LOG_DEBUG("WebRequestUtils_MakeInitialUrl_Hook localUrl: %s", il2cppi_to_string(localUrl).c_str());

    auto re = CALL_ORIGIN(WebRequestUtils_MakeInitialUrl_Hook, targetUrl, localUrl, method);
    std::string reurl = il2cppi_to_string(re);
    LOG_DEBUG("WebRequestUtils_MakeInitialUrl_Hook return: %s", reurl.c_str());
    get_proxy();
    if (proxy && !proxyhost.empty()) {
        std::string original_url = reurl;
    
        std::string::size_type pos = reurl.find("://");
        if (pos != std::string::npos) {
            pos += 3;
            std::string::size_type pos_end = reurl.find('/', pos);
            if (pos_end == std::string::npos) {
                pos_end = reurl.size();
            }
            std::string host = reurl.substr(pos, pos_end - pos);
       
            if (host.find("gryphline.com") != std::string::npos ||
                host.find("hg-cdn.com") != std::string::npos ||
                host.find("hypergryph.com") != std::string::npos) {
                reurl.replace(pos, pos_end - pos, proxyhost);
                }
        }
   
        std::string https_prefix = "https://";
        std::string http_prefix = "http://";
        if (reurl.compare(0, https_prefix.length(), https_prefix) == 0) {
            reurl.replace(0, https_prefix.length(), http_prefix);
        }
    
        LOG_WARNING("Proxy: %s --> %s", original_url.c_str(), reurl.c_str());
        return string_to_il2cppi(reurl);
    }
    return re;
}
app::String* UnityWebRequest_get_url_Hook (void/*app::UnityWebRequest*/* __this, app::MethodInfo* method) {
    auto re =CALL_ORIGIN(UnityWebRequest_get_url_Hook, __this, method);
    LOG_DEBUG("UnityWebRequest_get_url_Hook return: %s", il2cppi_to_string(re).c_str());

    //todo
    return re;
}
DWORD WINAPI MainThread(LPVOID lpReserved) {
    AllocConsole();
    FILE* Dummy;
    freopen_s(&Dummy, "CONOUT$", "w", stdout);
    freopen_s(&Dummy, "CONIN$", "w", stderr);
    SetConsoleTitle(TEXT("FootControl Console"));
    SetConsoleOutputCP(CP_UTF8);
    LOG_INFO("Starting...");

    while (!FindWindowA("UnityWndClass", nullptr))
        Sleep(3000);

    LOG_INFO("Initializing IL2CPP...");
   init_il2cpp();
   
   HookManager::install(app::WebRequestUtils_MakeInitialUrl, WebRequestUtils_MakeInitialUrl_Hook);
   HookManager::install(app::UnityWebRequest_get_url, UnityWebRequest_get_url_Hook);
    Sleep(5000);
    LOG_INFO("Initialized IL2CPP");


    auto& settings = cheat::Settings::getInstance();
    int initDelay = settings.f_InitDelay.getValue();

    //if (settings.f_ShowRpc.getValue()) {
    //    //g_Discord->Initialize();
    //    //g_Discord->Update();
    //    //LOG_INFO("Showing RPC...");
    //}

    LOG_INFO("Waiting %i seconds before starting DirectX...", initDelay / 1000);
    Sleep(initDelay);
    LOG_INFO("Waited, assuming that your game already opened. Opening menu...");

    __try {
        GetPresent();
        DetourDirectXPresent();
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        LOG_ERROR("Unhandled exception in opening menu.");
    }
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
      //  CloseHandle(CreateThread(NULL, 0, &initLua, NULL, NULL, NULL));
        CreateThread(NULL, 0, &MainThread, NULL, NULL, NULL);
    }
    return TRUE;
}
