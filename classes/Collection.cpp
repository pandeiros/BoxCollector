/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "Collection.h"

Collection::~Collection () {
    deleteBoxes ();
    if (mBoxArrangement != nullptr)
        delete mBoxArrangement;
}

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

void Collection::generateRandomData (unsigned long number, unsigned int max, unsigned int precision) {
    // Empty current container
    deleteBoxes ();

    // Generate boxes.
    for (unsigned long i = 0; i < number; ++i) {
        long randomValue = max * std::pow (10, precision);
        float l, w, h;
        l = (float)(rand () % randomValue);
        l /= (float)std::pow (10, precision);
        w = (float)(rand () % randomValue);
        w /= (float)std::pow (10, precision);
        h = (float)(rand () % randomValue);
        h /= (float)std::pow (10, precision);
        mBoxes.push_back (new Box (l, w, h));
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

void Collection::deleteBoxes () {
    // Clear container if not empty.
    if (mBoxes.size () != 0) {
        for (Box * box : mBoxes)
            delete box;
        mBoxes.clear ();
    }
}
