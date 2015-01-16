#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#define DATA_FOLDER "./Data/"
#define DEFAULT_DATA_FILE "data.txt"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Collection.h"
#include "MessageHandler.h"

/**
    
*/
class InputManager {
public:
    InputManager () : mFilename(DEFAULT_DATA_FILE) {
    };
    ~InputManager () {
    };

    // Constructor with filename parameter.
    // \param string filename : Name of the file to read data from.
    InputManager (const std::string filename);

    // Load data from file.
    bool loadData (Collection::Boxes & boxes);

    /// Setters

    void setFilename (const std::string filename);  // Set file name to read data from.

private:
    // Filename to read data from.
    std::string mFilename = "";

    // True if default constructor with default file name was used.
    bool isDefaultPath = true;
};

#endif

