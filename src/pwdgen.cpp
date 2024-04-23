#include <iostream>
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

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < length; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        password += charset[index];
    }

    return password;
}