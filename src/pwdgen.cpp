#include <string>
#include <cstdlib>
#include <ctime>

#include "pwdgen.h"

using namespace std;

string generateServicePassword(int length)
{
    static const char charset[] = "abcdefghijklmnopqrstubwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!£$^&*()@#";
    string password;
    password.reserve(length);

    static int counter = 0;
    srand(static_cast<unsigned int>(time(nullptr)) + counter);
    counter++;

    for (int i = 0; i < length; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        password += charset[index];
    }

    return password;
}

string generateHumanPassword()
{
    return "HelloWorld";
}