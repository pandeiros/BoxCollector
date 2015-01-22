/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include <iostream>
#include "Program.h"

int main (int argc, char *argv[]) {

    Program program (argc, argv);
    program.run ();

    std::cout << "\nProgram terminated. Press Enter to continue...";
    std::cin.get ();

    return 0;
}