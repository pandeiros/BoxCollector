/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "Program.h"

Program::Program (int argc, char* argv[]) : mInterface (argc, argv) {

}

void Program::run () {
#ifdef __DEBUG__
    MessageHandler::printDebugSection ("Parameters", true);
    mInterface.printParams ();
    mInterface.printHelp ();
    mInterface.printUsage ();
    MessageHandler::printDebugSection ("Parameters", false);
#endif

    // Load data.
    this->acquireData ();

#ifdef __DEBUG__
    MessageHandler::printDebugSection ("Collection content", true);
    mCollection.printAll ();
    MessageHandler::printDebugSection ("Collection content", false);
#endif
}

bool Program::acquireData () {
    std::string filename = mInterface.getStringParam ("--file");
    if (filename != "") {
        mInputManager.setFilename (filename);
        Collection::Boxes newBoxes;
        mInputManager.loadData (newBoxes);
        mCollection.setBoxes (newBoxes);
    }
    else {
        MessageHandler::printMessage("No input file to read from!\n", MessageHandler::ERROR);
        return false;
    }

    return true;
}