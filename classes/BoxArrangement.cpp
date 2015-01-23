/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "BoxArrangement.h"

BoxArrangement::BoxArrangement (BoxStack boxes, AlgorithmType type) :
mBoxes (boxes), mType (type) {

}

void BoxArrangement::arrange () {
    // Sorting based on heuristics.
    sort ();

    // Choose arranging method.
    switch (mType) {
        case VOLUME:
            arrangeVolume ();
            break;

        default:
            break;
    }
}

void BoxArrangement::printAll () {
    // Print header.
    std::cout << std::right << std::setw (7) << "Id " << "| ";
    std::cout << std::left << std::setw (8) << "Width" << "| ";
    std::cout << std::left << std::setw (8) << "Length" << "| ";
    std::cout << std::left << std::setw (8) << "Height" << "| ";
    std::cout << std::left << std::setw (12) << "Volume" << "\n";

    unsigned int stackNr = 0;
    for (BoxStack & stack : mStackGroup) {
        std::cout << " -------------------- Stack " << stackNr << " --------------------\n";
        for (Box * box : stack) {
            std::cout << *box;
        }
        ++stackNr;
        std::cout << "\n";
    }
}

void BoxArrangement::sort () {
    switch (mType) {
        case VOLUME:
            std::sort (mBoxes.begin (), mBoxes.end (),
                       [] (const Box * a, const Box * b) -> bool {
                return a->getVolume() > b->getVolume();
            });
            break;

        default:
            break;
    }
}

void BoxArrangement::arrangeVolume () {
    if (mBoxes.size () <= 1) {
        return;
    }

    // Check every box.
    for (Box * box : mBoxes) {
        bool inserted = false;

        // Nothing inserted.
        if (mStackGroup.size () == 0) {
            // Insert first box.
            BoxStack stack;
            stack.push_back (box);
            mStackGroup.push_back (stack);
            continue;
        }

        for (BoxStack & stack : mStackGroup) {
            // Check if box fits on top.
            if (stack.size () != 0 &&
                box->check (stack[stack.size () - 1])) {
                stack.push_back (box);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            // Insert new stack with this box.
            BoxStack stack;
            stack.push_back (box);
            mStackGroup.push_back (stack);
        }

    }

}
