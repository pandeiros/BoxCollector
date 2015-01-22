/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "MessageHandler.h"

void MessageHandler::printMessage (const std::string message, Type type) {
    std::cout << "\n<!> ERROR : " << message << "\n\n";
}

void MessageHandler::printDebugSection (const std::string title, bool isBegin) {
    if (isBegin) {
        std::cout << "====== Debug section: " << title << " ======\n";
    }
    else {
        std::cout << std::setw(10 + title.size()) << std::setfill ('=') << "" << " End of section ===\n\n";
        std::cout << std::setfill (' ');
    }

}