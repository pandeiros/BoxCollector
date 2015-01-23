#!bin/bash
g++ -o PROGRAM Source.cpp classes/Program.cpp classes/Interface.cpp classes/Collection.cpp classes/Box.cpp classes/BoxArrangement.cpp classes/InputManager.cpp classes/OutputManager.cpp \
classes/Utilities.cpp classes/MessageHandler.cpp -std=c++11 | grep error
