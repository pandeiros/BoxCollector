/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "Collection.h"

void Collection::printAll () {
    // Print header.
    std::cout << std::right << std::setw (7) << "Id " << "| ";
    std::cout << std::left << std::setw (8) << "Width" << "| ";
    std::cout << std::left << std::setw (8) << "Length" << "| ";
    std::cout << std::left << std::setw (8) << "Height" << "| ";
    std::cout << std::left << std::setw (12) << "Volume" << "\n";
    
    // Print content.    
    for (Box * box : mBoxes) {
        std::cout << *box;
    }
}

Collection::Boxes * Collection::getBoxes () {
    return &mBoxes;
}

BoxArrangement * Collection::getBoxArrangement () {
    return mBoxArrangement;
}

void Collection::setBoxes (Boxes & boxes) {
    this->mBoxes = boxes;
}

void Collection::setBoxArrangement (BoxArrangement * boxArrangement) {
    this->mBoxArrangement = boxArrangement;
}
