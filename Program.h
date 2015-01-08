/**
    Main project class. Aggregates i/o managers and box collection.
*/

#ifndef _PROGRAM_
#define _PROGRAM_

#include "Interface.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "Collection.h"
#include <iostream>

class Program {
public:
    Program () {
    };
    ~Program () {
    };

    // Constructor with input parameters to be passed to Interface
    Program (int argc, char* argv[]);

    // Main class method. Includes all operations and interfaces.
    void run ();

private:
    // Load data from file (if given)
    bool acquireData ();

    // Network modules
    Interface mInterface;
    InputManager mInputManager;
    OutputManager mOutputManager;
    Collection mCollection;
};

#endif

