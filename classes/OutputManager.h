/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _OUTPUT_MANAGER_
#define _OUTPUT_MANAGER_

#define OUTPUT_FOLDER "./tests/"
#define RESULTS_FOLDER "./tests/results/"
#define TEMPLATE_FOLDER "./tests/templates/"
#define GLOBAL_RESULTS_FILE "global_results.txt"
#define TEMPLATE_FILE "results_template.txt"

#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Collection.h"
#include "MessageHandler.h"
#include "Utilities.h"
#include "Interface.h"

/**
    Takes data from Collection and creates result files.
*/
class OutputManager {
public:
    OutputManager () {
    };
    ~OutputManager () {
    };

    // Collects all data and saves results. 
    // \param bool : Whether to use predefined path for files.
    bool saveResults (Collection * collection, Interface * interf, bool defaultPath = true);

    // Collects stats and saves them.
    // \param bool : Whether to use predefined path for files.
    bool saveGlobalResults (Collection * collection, Interface * interf);

    /// Setters

    void setResultsFilename (const std::string);

private:

    template <typename Type>
    std::string formatWidth (const Type value, const unsigned int width,
                             const char fill = '0', const std::string separator = " | ",
                             bool showPos = false);

    // Filenames (with default values)
    std::string mResultsFilename = "results";
};

#endif

template <typename Type>
inline std::string OutputManager::formatWidth (const Type value, const unsigned int width, 
                                               const char fill, const std::string separator, 
                                               bool showPos) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision (3) << std::left << std::setw (width)
        << std::setfill (fill) << (showPos ? std::showpos : std::noshowpos)
        << value << separator;

    return ss.str ();
}
