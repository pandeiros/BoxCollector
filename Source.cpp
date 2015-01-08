#include <iostream>
#include "Program.h"

int main (int argc, char *argv[]) {

    Program program (argc, argv);
    program.run ();

    std::cout << "\nProgram terminated. Press Enter to continue...";
    std::cin.get ();

    return 0;
}