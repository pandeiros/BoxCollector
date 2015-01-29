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
    Utilities::timeStart ();

    // Sorting based on heuristics.
    sort ();
    //arrangeBisect ();
    arrangeFirstBest ();

    // Choose arranging method.
    /*switch (mType) {
        case VOLUME:
            arrangeFirstBest ();
            break;
        case SD:
            arrangeFirstBest ();
            break;

        default:
            break;
    }*/

    mTime = Utilities::timeStop ();
}

void BoxArrangement::printAll () {
    // Print header.
    std::cout << std::right << std::setw (13) << "Id " << "| ";
    std::cout << std::left << std::setw (8) << "Width" << "| ";
    std::cout << std::left << std::setw (8) << "Length" << "| ";
    std::cout << std::left << std::setw (8) << "Height" << "| ";
    std::cout << std::left << std::setw (12) << "Volume" << "\n";

    std::cout << getAllStacks ();

}

std::string BoxArrangement::getAllStacks () {
    std::string content = "";
    unsigned int stackNr = 0;
    for (BoxStack & stack : mStackGroup) {
        content += "                                     Stack " + std::to_string (stackNr) + "\n";
        content += "--------------------------------------------------------------------------------------\n";
        for (Box * box : stack) {
            std::stringstream ss;
            ss << *box;
            content += ss.str ();
        }
        ++stackNr;
        content += "\n";
    }

    return content;
}

BoxArrangement::AlgorithmType BoxArrangement::getType () {
    return mType;
}

float BoxArrangement::getTotalVolume () {
    float sum = 0.f;
    for (BoxStack & stack : mStackGroup)
        sum += stack[0]->getVolume ();

    return sum;
}

unsigned int BoxArrangement::getSize () {
    return mStackGroup.size ();
}

float BoxArrangement::getTime () {
    return mTime;
}

void BoxArrangement::sort () {
    switch (mType) {
        case VOLUME:
            std::sort (mBoxes.begin (), mBoxes.end (),
                       [] (const Box * a, const Box * b) -> bool {
                return a->getVolume () > b->getVolume ();
            });
            break;
        case SD:
            std::sort (mBoxes.begin (), mBoxes.end (),
                       [] (const Box * a, const Box * b) -> bool {
                return a->getSD () < b->getSD ();
            });
            break;

        default:
            break;
    }
}

void BoxArrangement::arrangeFirstBest () {
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

void BoxArrangement::arrangeBisect () {
    if (mBoxes.size () <= 1) {
        return;
    }

    int left, right, pivot;
    int found = -1;


    for (Box * box : mBoxes) {
        left = 0;
        right = mStackGroup.size () - 1;
        pivot = (left + right + 1) / 2;
        found = -1;

        // No stacks so far.
        if (right < 0) {
            BoxStack stack;
            stack.push_back (box);
            mStackGroup.push_back (stack);
            continue;
        }

        // One stack with one element.
        if (right == 0) {
            if (box->check (mStackGroup[0][mStackGroup[0].size() - 1])) {
                mStackGroup[0].push_back (box);
            }
            else {
                BoxStack stack;
                stack.push_back (box);
                mStackGroup.push_back (stack);
            }
            continue;
        }

        // Find match by bisecting the box collection.
        while (pivot != right) {
            bool checked = box->check (mStackGroup[pivot][mStackGroup[pivot].size () - 1]);
            bool goingLeft = false;

            if (found != -1) {
                if (checked) {
                    goingLeft = true;
                }
                else {
                    goingLeft = false;
                }
            }
            else {
                if (checked)
                    found = pivot;

                goingLeft = true;
            }

            if (goingLeft)
                right = pivot;
            else
                left = pivot;
            pivot = (left + right + 1) / 2;

        }


        // Check the left one, because pivot won't check there if left and right are too close.
        if ((right - left) == 1) {
            if (box->check (mStackGroup[left][mStackGroup[left].size () - 1])) {
                mStackGroup[left].push_back (box);
                continue;
            }
        }

        if (box->check (mStackGroup[pivot][mStackGroup[pivot].size () - 1])) {
            mStackGroup[pivot].push_back (box);
           
        }
        // We found a good one, but kept on searching.
        else if (pivot < found) {
            mStackGroup[found].push_back (box);
        }
        else { 
            BoxStack stack;
            stack.push_back (box);
            mStackGroup.push_back (stack);
        }
    }
}
