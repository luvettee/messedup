#include "include/core/loader.hpp"

BOOL __stdcall DllMain(HANDLE hinstDLL, uint32_t fdwReason, void* lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        AllocConsole();
        SetConsoleTitleA("millionware.vip crack");
        freopen("CONOUT$", "w", stdout);
        CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(run), 0, 0, 0);
    }
    return TRUE;
}