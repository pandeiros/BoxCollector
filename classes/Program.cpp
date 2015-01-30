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

        MessageHandler::printMessage ("Loading data from file", MessageHandler::INFO);
        Utilities::timeStart ();
        this->acquireData ();
        MessageHandler::printMessage (std::to_string (Utilities::timeStop()), MessageHandler::TIME);
    }

    // Generate data.
    else if (mInterface.getStringParam ("--generate-tests") != "") {
        unsigned int tests = Utilities::convertFromString<unsigned int> (mInterface.getStringParam ("--generate-tests"));
        if (tests > 0) {
            MessageHandler::printMessage ("Generating records", MessageHandler::INFO);
            Utilities::timeStart ();
            this->mCollection.generateRandomData (tests, 100, 4);
            MessageHandler::printMessage (std::to_string (Utilities::timeStop ()), MessageHandler::TIME);
        }
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

    // Read parameters for algorithm.
    BoxArrangement::AlgorithmType aType = BoxArrangement::FB;
    BoxArrangement::HeuristicType hType = BoxArrangement::VOL;

    std::string aParam = "", hParam = "";
    aParam = mInterface.getStringParam ("--algorithm");
    hParam = mInterface.getStringParam ("--heuristic");

    if (aParam != "") {
        aParam == "BS" ? aType = BoxArrangement::BS : aType = BoxArrangement::FB;
    }

    if (hParam != "") {
        hParam == "SD" ? hType = BoxArrangement::SD : hType = BoxArrangement::VOL;
    }

    mCollection.setBoxArrangement (new BoxArrangement (
        *mCollection.getBoxes (), aType, hType));

    // Begin arranging.
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