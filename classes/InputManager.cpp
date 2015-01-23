/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "InputManager.h"

InputManager::InputManager (const std::string filename) :
mFilename (filename) {
    isDefaultPath = false;
}

bool InputManager::loadData (Collection::Boxes & boxes) {
    std::ifstream inputFile;
    std::string content = "";
    std::stringstream ss;

    // Try to open file and read from it.
    if (isDefaultPath) {
        mFilename = DATA_FOLDER + mFilename;
    }
    inputFile.open (mFilename, std::ios::in);
    if (!inputFile.is_open ()) {
        MessageHandler::printMessage ("Cannot open file: " + mFilename, MessageHandler::ERROR);
        return false;
    }

    // Copy file content into string.
    while (std::getline (inputFile, content)) {
        if (content[0] != '#') {
            Box * newBox = parseDataRow (content);
            if (newBox != nullptr)
                boxes.push_back (newBox);
            else {
                MessageHandler::printMessage ("Parsing row of data failed: nullptr returned", MessageHandler::ERROR);
                return false;
            }
        }
        else {
            // DO NOTHING.
            // Line with comment.
        }
    }
    

    inputFile.close ();

    return true;
}

Box * InputManager::parseDataRow (const std::string & row) {
    std::stringstream ss;
    ss.str(row);
    float w, l, h;
    Box * newBox = nullptr;

    try {
        ss >> l >> w >> h;
        newBox = new Box (l, w, h);
        return newBox;
    }
    catch (...) {
        if (newBox != nullptr)
            delete newBox;
        return nullptr;
    }

    return nullptr;
}

void InputManager::setFilename (const std::string filename) {
    mFilename = filename;
    isDefaultPath = false;
}
