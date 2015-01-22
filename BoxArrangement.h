/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _BOX_ARRANGEMENT_
#define _BOX_ARRANGEMENT_

#include <vector>
#include "Box.h"

/**
    Class for arranging Boxes so that they occupy as little space as possible.
    Provides different types of algorithms listed below.
*/
class BoxArrangement {
public:
    // Arranging algorithm types.
    enum AlgorithmType {

    };

    // Group of boxes stacked together.
    typedef std::vector<Box*> BoxStack;

    // Separate stacks of boxes.
    typedef std::vector<BoxStack> StackGroup;

    BoxArrangement () {
    };
    ~BoxArrangement () {
    };

    // Print info about all stacks and all boxes in each stack.
    void printAll ();

private:
    StackGroup mStackGroup;
};

#endif

