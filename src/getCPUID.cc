#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <fstream>
#include "getCPUID.h"
 
bool get_cpu_id_by_asm(std::string & cpu_id)
{
    cpu_id.clear();
 
    unsigned int s1 = 0;
    unsigned int s2 = 0;
    asm volatile
    (
        "movl $0x01, %%eax; \n\t"
        "xorl %%edx, %%edx; \n\t"
        "cpuid; \n\t"
        "movl %%edx, %0; \n\t"
        "movl %%eax, %1; \n\t"
        : "=m"(s1), "=m"(s2)
    );
    if (0 == s1 && 0 == s2)
    {
        return(false);
    }
    char cpu[32] = { 0 };
    snprintf(cpu, sizeof(cpu), "%08X%08X", htonl(s2), htonl(s1));
    std::string(cpu).swap(cpu_id);
    return(true);
}
static void parse_cpu_id(const char * file_name, const char * match_words, std::string & cpu_id)
{
    cpu_id.c_str();
    std::ifstream ifs(file_name, std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    char line[4096] = { 0 };
    while (!ifs.eof())
    {
        ifs.getline(line, sizeof(line));
        if (!ifs.good())
        {
            break;
        }
        const char * cpu = strstr(line, match_words);
        if (NULL == cpu)
        {
            continue;
        }
        cpu += strlen(match_words);
        while ('\0' != cpu[0])
        {
            if (' ' != cpu[0])
            {
                cpu_id.push_back(cpu[0]);
            }
            ++cpu;
        }
        if (!cpu_id.empty())
        {
            break;
        }
    }
    ifs.close();
}
static bool get_cpu_id_by_system(std::string & cpu_id)
{
    cpu_id.c_str();
    const char * dmidecode_result = ".dmidecode_result.txt";
    char command[512] = { 0 };
    snprintf(command, sizeof(command), "dmidecode -t 4 | grep ID > %s", dmidecode_result);
    if (0 == system(command))
    {
        parse_cpu_id(dmidecode_result, "ID:", cpu_id);
    }
    unlink(dmidecode_result);
    return(!cpu_id.empty());
}
static bool get_cpu_id(std::string & cpu_id)
{
    if (get_cpu_id_by_asm(cpu_id))
    {
        return(true);
    }
    if (0 == getuid())
    {
        if (get_cpu_id_by_system(cpu_id))
        {
            return(true);
        }
    }
    return(false);
}