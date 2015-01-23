/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "OutputManager.h"

bool OutputManager::saveResults (Collection * collection, Interface * interf, bool defaultPath) {
    std::fstream output;
    std::ifstream templateFile;
    std::string resultsPath = mResultsFilename, templatePath = TEMPLATE_FOLDER,
        templateContent = "", currentDateTime = "";
    std::stringstream ss;

    // Acquire desired final path.
if (defaultPath) {
time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"_%d-%m-%Y_%I-%M-%S",timeinfo);
  std::string str(buffer);

  currentDateTime = str;
//Utilities::replaceKeyword (":", "-", currentDateTime);
    resultsPath = RESULTS_FOLDER + resultsPath + currentDateTime;
currentDateTime = currentDateTime.substr(1, currentDateTime.size() - 2);
        /*auto time = std::time (nullptr);
        auto localTime = *std::localtime (&time);
        std::stringstream ss;
        ss << std::put_time (&localTime, "_%Y-%m-%d_%H.%M.%S.txt");
        resultsPath = RESULTS_FOLDER + resultsPath + ss.str ();
        ss.str ("");
        ss << std::put_time (&localTime, "%Y-%m-%d %H:%M:%S");
        currentDateTime = ss.str ();*/
    }

    // Open file template with prepared header
    templatePath += TEMPLATE_FILE;
    templateFile.open (templatePath, std::ios::in);
    if (!templateFile.is_open ()) {
        MessageHandler::printMessage ("Cannot open cross validation stats template file! (file: " + templatePath + ")",
                                      MessageHandler::ERROR);
        return false;
    }

    // Copy template data into stringstream and then into string
    ss.str ("");
    ss << templateFile.rdbuf ();
    templateContent = ss.str ();

    // Open file.
    output.open (resultsPath, std::ios::out | std::ios::trunc);
    if (!output.is_open ()) {
        MessageHandler::printMessage ("Saving results to file failed!(file: " + resultsPath + ")",
                                      MessageHandler::ERROR);
        return false;
    }

    // Prepare headers
    Utilities::replaceKeyword ("$date", currentDateTime, templateContent);
    Utilities::replaceKeyword ("$records", std::to_string (collection->getBoxes ()->size ()), templateContent);
    Utilities::replaceKeyword ("$input", interf->getStringParam ("--file"), templateContent);
    Utilities::replaceKeyword ("$algo", interf->getStringParam ("--algorithm"), templateContent);
    Utilities::replaceKeyword ("$time", std::to_string (collection->getBoxArrangement ()->getTime ()), templateContent);
    Utilities::replaceKeyword ("$stacks", std::to_string (collection->getBoxArrangement ()->getSize ()), templateContent);
    Utilities::replaceKeyword ("$volume", std::to_string (collection->getBoxArrangement ()->getTotalVolume ()), templateContent);
    Utilities::replaceKeyword ("$rows", collection->getBoxArrangement ()->getAllStacks (), templateContent);

    // Save stats.
    output << templateContent;
    output.close ();

    return true;
}

bool OutputManager::saveGlobalResults (Collection * collection, Interface * interf) {
    std::fstream output;
    std::string globalStatsPath = OUTPUT_FOLDER, currentDateTime = "";
    globalStatsPath += GLOBAL_RESULTS_FILE;

    // Open global file.
    output.open (globalStatsPath, std::ios::out | std::ios::app);
    if (!output.is_open ()) {
        MessageHandler::printMessage ("Saving global results to file failed!  (file: " + globalStatsPath + ")", MessageHandler::ERROR);
        return false;
    }

    // Obtain date.
    /*auto time = std::time (nullptr);
    auto localTime = *std::localtime (&time);
    std::stringstream ss;
    ss << std::put_time (&localTime, "%Y-%m-%d %H:%M:%S");
    currentDateTime = ss.str ();*/
// Acquire desired final path.
//    if (defaultPath) {
time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y_%H-%M-%S",timeinfo);
  std::string str(buffer);

  currentDateTime =  str;

//Utilities::replaceKeyword (":", "-", currentDateTime);



    // Prepare output
    std::string row = "";
    std::string separator = " | ";


    // Save formatted file data.
    output << currentDateTime << " | ";
    row += formatWidth<unsigned int> (collection->getBoxes ()->size (), 10, ' ', separator);
    row += formatWidth<std::string> (interf->getStringParam ("--file"), 28, ' ', separator);
    row += formatWidth<std::string> (interf->getStringParam ("--output"), 28, ' ', separator);
    row += formatWidth<std::string> (interf->getStringParam ("--algorithm"), 15, ' ', separator);
    row += formatWidth<float> (collection->getBoxArrangement()->getTime(), 8, ' ', separator);    

    // Save data.
    output << row << "\n";
    output.close ();

    return true;
}

void OutputManager::setResultsFilename (const std::string filename) {
    this->mResultsFilename = filename;
}
