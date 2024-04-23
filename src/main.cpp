#include <iostream>
#include <string.h>

#include "pwdgen.h"
#include "cat.h"
#include "specs.h"

using namespace std;

int main(int argc, char* argv[])
{

    // Check for CLI arguments.
    if (argc == 1) {
        cerr << "Error: No arguments passed to itt.\n";
        return 1;
    }

    // Easter egg.
    if (strcmp(argv[1], "cat") == 0) {
        if (argc == 2) {
            printCat();
        } else {
            if (strcmp(argv[2], "big") == 0) {
                printLargeCat();
            }
        }
    }

    // Password generation module.
    // TODO: Make this more readable.
    if (strcmp(argv[1], "pwd") == 0 && strcmp(argv[2], "service") == 0) {
        int count = (argc == 4) ? atoi(argv[3]) : 1;
        for (int i = 0; i < count; ++i) {
            string backPw = generateServicePassword(24);
            cout << backPw << endl;
        }
    } else if (strcmp(argv[1], "pwd") == 0 && strcmp(argv[2], "human") == 0) {
        int count = (argc == 4) ? atoi(argv[3]) : 1;
        for (int i = 0; i < count; ++i) {
            string backPw = generateHumanPassword();
            cout << backPw << endl;
        }
    }

    // Specs module.
    if (strcmp(argv[1], "specs") == 0) {
        getSpecs();
    }

    return 1;
}