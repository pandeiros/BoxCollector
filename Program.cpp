#include "Program.h"

Program::Program (int argc, char* argv[]) : mInterface (argc, argv) {

}

void Program::run () {
    // TEMP
    mInterface.printParams ();
    mInterface.printHelp ();
    mInterface.printUsage ();

}

bool Program::acquireData () {
    std::string filename = mInterface.getStringParam ("--file");
    if (filename != "") {
        mInputManager.setFilename (filename);
        mInputManager.loadData (*mCollection.getBoxes());
    }
    else {
        std::cout << " >> ERROR: No input file to read from!\n";
        return false;
    }

    return true;
}