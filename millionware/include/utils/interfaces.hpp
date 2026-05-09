#pragma once

#include "../../common.hpp"
#include <string>
#include <unordered_map>

struct module_info_t
{
    uint32_t start = 0;
    uint32_t end = 0;
    std::string name = "";
};

typedef void* (*create_interface_fn)(const char* pName, int* pReturnCode);

create_interface_fn get_module_factory(HMODULE module);
void* get_interface(HMODULE module, const char* interface_version);

void init_interfaces();
const std::unordered_map<uint32_t, std::string>& get_interfaces();