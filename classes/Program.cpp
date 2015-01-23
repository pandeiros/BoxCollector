/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

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
#else
    if (mInterface.getBoolParam ("--help")) {
        mInterface.printHelp ();
        return;
    }
    else if (mInterface.getBoolParam ("--usage")) {
        mInterface.printUsage ();
        return;
    }
#endif

    // Load data.
    if (mInterface.getStringParam ("--file") != "") {
        if (mInterface.getStringParam ("--generate-tests") != "")
            MessageHandler::printMessage ("Input file given and data generation requested - generating ignored.",
            MessageHandler::WARNING);
        this->acquireData ();
    }
    // Generate data.
    else if (mInterface.getStringParam ("--generate-tests") != "") {
        unsigned int tests = Utilities::convertFromString<unsigned int> (mInterface.getStringParam ("--generate-tests"));
        if (tests > 0)
            // TODO
            // Parametrize these values:
            this->mCollection.generateRandomData (tests, 50, 3);
        else {
            MessageHandler::printMessage ("Number of tests is equal or less than 0.", MessageHandler::ERROR);
            return;
        }
    }

#ifdef __DEBUG__
    MessageHandler::printDebugSection ("Collection content", true);
    mCollection.printAll ();
    MessageHandler::printDebugSection ("Collection content", false);
#endif

    mCollection.setBoxArrangement (new BoxArrangement (
        *mCollection.getBoxes (), BoxArrangement::VOLUME));

    mCollection.getBoxArrangement ()->arrange ();

#ifdef __DEBUG__
    MessageHandler::printDebugSection ("Boxes arrangement", true);
    mCollection.getBoxArrangement ()->printAll ();
    MessageHandler::printDebugSection ("Boxes arrangement", false);
#endif


    // Saving results
    std::string filename = mInterface.getStringParam ("--output");
    if (filename != "") {
        mOutputManager.setResultsFilename (filename);
        mOutputManager.saveResults (&mCollection, &mInterface, false);
    }
    else
        mOutputManager.saveResults (&mCollection, &mInterface);

    // Saving global results
    mOutputManager.saveGlobalResults (&mCollection, &mInterface);
   

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
        MessageHandler::printMessage ("No input file to read from!\n", MessageHandler::ERROR);
        return false;
    }

    return true;
}