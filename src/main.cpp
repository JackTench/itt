#include <iostream>
#include <string.h>

#include "pwdgen.h"

using namespace std;

int main(int argc, char* argv[])
{

    // Check for CLI arguments.
    if (argc == 1) {
        cerr << "Error: No arguments passed to itt.\n";
        return 1;
    }

    // Password generation module.
    if (strcmp(argv[1], "pwd") == 0) {
        // Service passwords.
        if (strcmp(argv[2], "service") == 0) {
            // TODO: Change this from test code to user input. This is only temporary.
            for (int i = 0; i < 10; ++i) {
                string backPw = generateServicePassword(24);
                cout << backPw << endl;
            }
        }
    }

    return 1;
}