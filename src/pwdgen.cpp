#include <string>
#include <cstdlib>
#include <ctime>

#include "pwdgen.h"
#include "dictionary.h"

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
    string password;

    // Seed RNG.
    static int counter = 0;
    srand(static_cast<unsigned int>(time(nullptr)) + counter);
    counter++;

    // Select random indexes and get words. Change first letter to upper case.
    int index1 = rand() % Dictionary::dictionary.size();
    int index2 = rand() % Dictionary::dictionary.size();
    string word1 = Dictionary::dictionary[index1];
    string word2 = Dictionary::dictionary[index2];
    word1[0] = toupper(word1[0]);
    word2[0] = toupper(word2[0]);
    password += word1;
    password += word2;

    // Generate random 3 digit number.
    int number = rand() % 900 + 100;
    password += to_string(number);

    // Generate random punctuation.
    static const char puncset[] = "!£$^&*()@";
    int index3 = rand() % (sizeof(puncset) - 1);
    password += puncset[index3];

    return password;
}