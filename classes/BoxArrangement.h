/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _BOX_ARRANGEMENT_
#define _BOX_ARRANGEMENT_

#include <algorithm>
#include <vector>
#include <iostream>
#include "Box.h"

/**
    Class for arranging Boxes so that they occupy as little space as possible.
    Provides different types of algorithms listed below.
*/
class BoxArrangement {
public:
    // Arranging algorithm types.
    enum AlgorithmType {
        // Boxes' volume based sort and arrange order.
        VOLUME
    };

    // Group of boxes stacked together.
    typedef std::vector<Box*> BoxStack;

    // Separate stacks of boxes.
    typedef std::vector<BoxStack> StackGroup;

    BoxArrangement () {
    };
    ~BoxArrangement () {
    };

    // Constructor with copy of the boxes from Collection and specified algorithm to be used.
    BoxArrangement (BoxStack boxes, AlgorithmType type);

    // Start arranging (with previously specified algorithm).
    void arrange ();

    // Print info about all stacks and all boxes in each stack.
    void printAll ();

private:
    // Sort all stored boxes by special criteria.
    void sort ();

    /// Different arranging algorithms.

    void arrangeVolume ();  // AlgorithmType::VOLUME

    // All boxes.
    BoxStack mBoxes;

    // Separate stacks of boxes.
    StackGroup mStackGroup;

    // Type of algorithm used.
    AlgorithmType mType;
};

#endif

