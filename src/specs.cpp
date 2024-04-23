#include <iostream>

#ifdef _WIN32
#include <windows.h>
#elif __unix__
#include <sys/utsname.h>
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

void getSpecs()
{
    getOS();
}