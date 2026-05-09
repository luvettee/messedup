#include "../utils/pattern.hpp"

int find_pattern(const char* module, const char* pattern, int offset)
{
    int pattern_bytes[256];
    int pattern_bytes_size = 0;

    for (const char* current = pattern; current < pattern + strlen(pattern); ++current)
    {
        if (*current == '?')
        {
            ++current;
            if (*current == '?')
                ++current;
            pattern_bytes[pattern_bytes_size] = -1;
            pattern_bytes_size++;
        }
        else
        {
            pattern_bytes[pattern_bytes_size] = strtoul(current, const_cast<char**>(&current), 16);
            pattern_bytes_size++;
        }
    }

    BYTE* scan_address = reinterpret_cast<BYTE*>(LoadLibraryA(module));
    auto dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(scan_address);
    auto nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(scan_address + dos_header->e_lfanew);
    int scan_size = nt_headers->OptionalHeader.SizeOfImage - pattern_bytes_size;

    for (int i = 0; i < scan_size; i++)
    {
        bool found = true;
        for (int j = 0; j < pattern_bytes_size; ++j)
        {
            if (scan_address[i + j] != pattern_bytes[j] && pattern_bytes[j] != -1)
            {
                found = false;
                break;
            }
        }
        if (found)
            return reinterpret_cast<int>(&scan_address[i]) + offset;
    }

    printf("Failed to find %s in %s\n", pattern, module);
    system("pause");
    return 0;
}