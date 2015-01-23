/**
    Non-instantiable class. Provides various string operations.
*/

#ifndef UTILITIES
#define UTILITIES

#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
#include "MessageHandler.h"

class Utilities {
public:
    // Clocks for time measurement.
    static clock_t begin, end;

    // Start time measurement.
    static void timeStart ();

    // Stop time measurement. Return time in second.
    static float timeStop ();

    // Converts given argument from std::string to Type
    template <typename Type>
    static Type convertFromString (const std::string value);

    // Replace file keyword with proper data
    // \param string keyword : Keyword in file to be found and replaced.
    // \param string value : String to be inserted instead of the given keyword.
    // \param string & text : Reference to text, in which the replacement is done.
    static void replaceKeyword (const std::string keyword, std::string value, std::string & text);
};


template <typename Type>
inline Type Utilities::convertFromString (const std::string value) {
    std::stringstream ss;
    ss.str (value);
    Type conversion;
    ss >> conversion;
    return conversion;
}

#endif
