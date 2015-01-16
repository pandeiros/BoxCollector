#include "InputManager.h"

InputManager::InputManager (const std::string filename) :
mFilename (filename) {
}

Collection::Boxes InputManager::loadData () {
    std::ifstream inputFile;
    std::string content = "";

    // Try to open file and read from it.
}

void InputManager::setFilename (const std::string filename) {
    mFilename = filename;
}
