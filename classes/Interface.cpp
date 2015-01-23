/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "Interface.h"

Interface::Interface (int argc, char* argv[]) : mArgCount (argc) {
    configureParameters ();

    for (int i = 1; i < mArgCount; ++i) {

        std::string parameter (argv[i]);

        if (mapParamBools.find (parameter) != mapParamBools.end () && mapParamBools[parameter].first != true) {
            mapParamBools[parameter].first = mapParamBools[mapParamBools[parameter].second].first = true;
        }
        else if (mapParamStrings.find (parameter) != mapParamStrings.end () &&
                 i + 1 < mArgCount &&
                 mapParamStrings[parameter].first == "") {
            std::string filename (argv[i + 1]);
            mapParamStrings[parameter].first = mapParamStrings[mapParamStrings[parameter].second].first = filename;
            i++;
            continue;
        }
        else {
            mapParamBools["--usage"].first = true;
            mapParamBools["-u"].first = true;
            break;
        }
    }
}

void Interface::configureParameters () {
    // Bool parameters: exists or not.
    mapParamBools["--usage"] = std::make_pair (false, "-u");
    mapParamBools["-u"] = std::make_pair (false, "--usage");
    mapParamBools["--help"] = std::make_pair (false, "-h");
    mapParamBools["-h"] = std::make_pair (false, "--help");

    // Parameters with extra value (necessary).
    mapParamStrings["--file"] = std::make_pair ("", "-f");
    mapParamStrings["-f"] = std::make_pair ("", "--file");
    mapParamStrings["--output"] = std::make_pair ("", "-o");
    mapParamStrings["-o"] = std::make_pair ("", "--output");
    mapParamStrings["--generate-tests"] = std::make_pair ("", "--generate-tests");
    mapParamStrings["--algorithm"] = std::make_pair ("", "--algorithm");
}

void Interface::printParams () {
    // Print usage and help params
    for (auto &x : mapParamBools) {
        if (x.second.first == true)
            std::cout << x.first << "\n";
    }

    // Print filenames params
    for (auto &x : mapParamStrings) {
        if (x.second.first != "")
            std::cout << std::left << std::setw (15) << x.first << "==>\t" << x.second.first << "\n";
    }

    std::cout << "\n";
}

void Interface::printHelp () {
    std::cout << mHelpMessage << "\n\n";
}

void Interface::printUsage () {
    std::cout << mUsageMessage << "\n\n";
}

std::string Interface::getStringParam (const std::string key) {
    if (mapParamStrings.find (key) != mapParamStrings.end ())
        return mapParamStrings[key].first;
    else
        return "";
}

bool Interface::getBoolParam (const std::string key) {
    if (mapParamBools.find (key) != mapParamBools.end ())
        return mapParamBools[key].first;
    else {
        MessageHandler::printMessage ("Requested wrong parameter: false returned", MessageHandler::WARNING);
        return false;
    }
}