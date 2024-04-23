#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#elif __unix__
#include <sys/utsname.h>
#include <fstream>
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
    cout << "Operating System Unknown" << endl;
#endif
}

void getCPU()
{
#ifdef _WIN32
    cout << "Not yet implemented." << endl;
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
    cout << "Not yet implemented." << endl;
#endif
}

void getSpecs()
{
    getOS();
    getCPU();
}