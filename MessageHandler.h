/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _MESSAGE_HANDLER_
#define _MESSAGE_HANDLER_

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

/**
    Non-instantiable class for displaying formatted message results.
    Provides 3 message types: errors, warnings and information messages.
    Contains predefined templates for popular messages.
*/
class MessageHandler {
public:
    // Message type
    enum Type {
        UNKNOWN,
        INFO,
        WARNING,
        ERROR
    };

    // TODO Implement later.
    // Message type headers.
    //static const std::map <Type, std::string> ErrorHeaders;

    // Prints custom message.
    // \param string message : Message to be display
    // \param (opt) Type type : Type of the message.
    // \see MessageHandler::Type
    static void printMessage (const std::string message, Type type = Type::UNKNOWN);

    // Prints custom debug section indicator.
    // \param string title : Debug section title.
    // \param bool isBegin : True if start of the sectiom false if end.
    static void printDebugSection (const std::string title, bool isBegin);
};

#endif

