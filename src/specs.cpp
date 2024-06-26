#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <cstdint>
#elif __unix__
#include <sys/utsname.h>
#include <fstream>
#include <sstream>
#endif

using namespace std;

void getOS()
{
#ifdef _WIN32
    DWORD dwVersion = GetVersion();
    DWORD dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    DWORD dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
    cout << "Operating System: Windows " << dwMajorVersion << "." << dwMinorVersion << endl;
#elif __unix__
    struct utsname unameData;
    uname(&unameData);
    cout << "Operating System: " <<unameData.sysname << " " << unameData.release << endl;
#else
    cout << "Operating System: Unknown" << endl;
#endif
}

void getCPU()
{
#ifdef _WIN32
    HKEY hKey;
    DWORD dwType = REG_SZ;
    char szBuffer[256];
    DWORD dwBufferSize = sizeof(szBuffer);
    string cpuModel;

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        if (RegQueryValueEx(hKey, "ProcessorNameString", NULL, &dwType, (LPBYTE)szBuffer, &dwBufferSize) == ERROR_SUCCESS) {
            cpuModel = szBuffer;
        }
        RegCloseKey(hKey);
    }

    cout << "CPU: " << cpuModel << endl;
#elif __unix__
    ifstream cpuinfo("/proc/cpuinfo");
    string line;
    string cpuModel;

    while (getline(cpuinfo, line)) {
        if (line.substr(0, 10) == "model name") {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                cpuModel = line.substr(pos + 2);
                break;
            }
        }
    }

    cpuinfo.close();
    
    cout << "CPU: " << cpuModel << endl;
#else
    cout << "CPU: Not yet implemented." << endl;
#endif
}

void getRAM()
{
#ifdef _WIN32
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);
    GlobalMemoryStatusEx(&memoryStatus);
    uint64_t totalRAM = memoryStatus.ullTotalPhys;
    cout << "RAM: " << to_string(totalRAM / (1024 * 1024)) << " MB" << endl;
#elif __unix__
    ifstream meminfo("/proc/meminfo");
    string line;
    string ramAmount;

    while (getline(meminfo, line)) {
        if (line.substr(0, 8) == "MemTotal") {
            istringstream iss(line);
            string token;
            iss >> token;
            int amount;
            if (iss >> amount) {
                ramAmount = to_string(amount / 1024) + " MB";
                break;
            }
        }
    }

    meminfo.close();

    cout << "RAM: " << ramAmount << endl;
#else
    cout << "RAM: Not yet implemented." << endl;
#endif
}

void getSpecs()
{
    getOS();
    getCPU();
    getRAM();
}