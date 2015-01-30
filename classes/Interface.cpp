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
    mapParamStrings["--heuristic"] = std::make_pair ("", "--heuristic");
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
    std::cout << " >> Help <<\n";
    std::cout << std::left;
    std::cout << "Box Collector\n";
    std::cout << "Simple program to solve problem with not enough space to store Your boxes!\n";
    std::cout << "Provides quick solution in packing boxes in one another.\n\n";
    std::cout << "Algorithm types:\n";
    std::cout << "  FB - First Best : Iterate from the beginning to find suitable box.\n";
    std::cout << "  BS - Bisect : Repeat dividing the set into half and checking boxes.\n\n";
    std::cout << "Heuristics available:\n";
    std::cout << "  VOL - Volume : Sort by volume of the boxes, descending.\n";
    std::cout << "  SD - Standard Deviation : Sort by standard deviation of the box's sizes, descending.\n\n";
    std::cout << "Use   --usage   parameter to check available options.\n";
}

void Interface::printUsage () {
    std::cout << " >> Usage:\n";
    std::cout << std::left;
    int size = 35;
    std::cout << std::setw (size) << " -h | --help" << " : Prints useful information about program.\n";
    std::cout << std::setw (size) << " -u | --usage" << " : Prints message with possible input parameters.\n";
    std::cout << std::setw (size) << " -f | --file[filename]" << " : Input file with information about boxes.\n";
    std::cout << std::setw (size) << " -o | --output[filename]" << " : Output file to be created with program results.\n";
    std::cout << std::setw (size) << " --generate-tests [number_of_boxes]" << " : Forces program to generate its own tests in given number.\n";
    std::cout << std::setw (size) << " --algorithm [FB | BS]" << " : Specifies which arrange algorithm to use (default FB).\n";
    std::cout << std::setw (size) << " --heuristic [VOL | SD]" << " : Specifies which sorting heuristic to use (default VOL).\n";
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