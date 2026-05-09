#pragma once

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <windows.h>
#include <cstdint>
#include <cstdio>
#include <cstring>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Ws2_32.lib")