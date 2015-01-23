/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _PROGRAM_
#define _PROGRAM_

#include <iostream>
#include "Interface.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "Collection.h"
#include "MessageHandler.h"
#include "Utilities.h"

/**
    Main project class. Aggregates i/o managers and box collection.
*/
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

