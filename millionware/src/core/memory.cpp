#include "../core/memory.hpp"

struct memory_region_t
{
    void* address;
    size_t size;
    const char* description;
};

static memory_region_t g_regions[] = {
    { reinterpret_cast<void*>(0x30930000), 0x0041D000, "hack_address" },
    { reinterpret_cast<void*>(0x1860000),   0x00001000, "user_struct" },
    { reinterpret_cast<void*>(0x1870000),   0x00001000, "runtime_table" },
    { reinterpret_cast<void*>(0x1880000),   0x00001000, "runtime_table_2" }
};

void* allocate_required_memory()
{
    printf("[+] Allocating required memory regions...\n");

    for (int i = 0; i < 4; ++i)
    {
        memory_region_t& region = g_regions[i];
        
        void* allocated = VirtualAlloc(region.address, region.size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        if (!allocated)
        {
            printf("[-] Failed to allocate %s at 0x%X (size: 0x%X)\n", 
                   region.description, 
                   reinterpret_cast<uint32_t>(region.address), 
                   region.size);
            return nullptr;
        }
        
        printf("[+] Allocated %s at 0x%X (size: 0x%X)\n", 
               region.description,
               reinterpret_cast<uint32_t>(allocated),
               region.size);
    }

    return g_regions[0].address;
}

bool verify_memory_regions()
{
    for (int i = 0; i < 4; ++i)
    {
        memory_region_t& region = g_regions[i];
        
        MEMORY_BASIC_INFORMATION mem;
        if (!VirtualQuery(region.address, &mem, sizeof(mem)))
        {
            printf("[-] Failed to query memory for %s\n", region.description);
            return false;
        }

        if (mem.RegionSize < region.size)
        {
            printf("[-] Memory region %s has incorrect size (expected: 0x%X, got: 0x%X)\n",
                   region.description,
                   region.size,
                   static_cast<size_t>(mem.RegionSize));
            return false;
        }
    }

    return true;
}

void free_memory_regions()
{
    for (int i = 0; i < 4; ++i)
    {
        memory_region_t& region = g_regions[i];
        VirtualFree(region.address, 0, MEM_RELEASE);
    }
}