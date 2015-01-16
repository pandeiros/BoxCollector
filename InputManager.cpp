#include "InputManager.h"

InputManager::InputManager (const std::string filename) :
mFilename (filename) {
    isDefaultPath = false;
}

bool InputManager::loadData (Collection::Boxes & boxes) {
    std::ifstream inputFile;
    std::string content = "";

    // Try to open file and read from it.
    if (isDefaultPath) {
        mFilename = DATA_FOLDER + mFilename;
    }
    inputFile.open (mFilename, std::ios::in);
    if (!inputFile.is_open ()) {
        MessageHandler::printMessage ("Cannot open file " + mFilename, MessageHandler::ERROR);
        return false;
    }

    return true;
}

void InputManager::setFilename (const std::string filename) {
    mFilename = filename;
}
