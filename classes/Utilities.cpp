#include "Utilities.h"

clock_t Utilities::end = 0;
clock_t Utilities::begin = 0;

void Utilities::timeStart () {
    begin = clock ();
}

float Utilities::timeStop () {
    end = clock ();
    return (end - begin) / (float)CLOCKS_PER_SEC;
}

void Utilities::replaceKeyword (const std::string keyword, std::string value, std::string & text) {
    if (value == "")
        value = "-";

    // If keyword is not found, print an error.
    unsigned int keywordPos = text.find (keyword);
    if (keywordPos == std::string::npos) {
        MessageHandler::printMessage ("Keyword '" + keyword + "' cannot be found!", MessageHandler::ERROR);
        return;
    }

    // Otherwise...
    while (keywordPos != std::string::npos) {
        std::string before = "", after = "";
        before = text.substr (0, keywordPos);
        after = text.substr (keywordPos + keyword.size (), text.size () - (keywordPos + keyword.size ()));

        text = before + value + after;
        keywordPos = text.find (keyword);
    }
}