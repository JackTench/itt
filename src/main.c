#include <stdio.h>

#include "cat.h"

int main(int argc, char* argv[])
{

    // Check for CLI arguments.
    if (argc == 1) {
        printf("Error: No arguments passed to itt.\n");
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

    return 1;
}