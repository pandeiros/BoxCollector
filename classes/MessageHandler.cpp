/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "MessageHandler.h"

void MessageHandler::printMessage (const std::string message, Type type) {
    switch (type) {
        case ERROR:
            std::cout << "\n<!!!> ERROR : " << message << "\n\n";
            break;
        case WARNING:
            std::cout << "\n<?> Warning : " << message << "\n\n";
            break;
        case INFO:
            std::cout << "\n   > > >  " << message << "  < < <\n\n";
            break;
        case TIME:
            std::cout << "=============== Time:\t" << message << " [sec] ====\n\n";
            break;

        default:
            break;
    }
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