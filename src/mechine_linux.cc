#include "getCPUID.h"
#include "getProcessorId.h"
#include "getMacAddress.h"
#include <iostream>
#include <map>
using namespace std;
map<string, string> getInfo () {
    string cpuId, processorId, macAddress;
    get_cpu_id_by_asm(cpuId);
    get_board_serial_number(processorId);
    get_mac_address(macAddress);
    map<string, string> resInfo;
    resInfo.insert(pair<string, string>("cpuId", cpuId ));
    resInfo.insert(pair<string, string>("baseBoard", processorId ));
    resInfo.insert(pair<string, string>("macAddress", macAddress ));
    return resInfo;
}