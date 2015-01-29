/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _BOX_ARRANGEMENT_
#define _BOX_ARRANGEMENT_

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include "Box.h"
#include "Utilities.h"

/**
    Class for arranging Boxes so that they occupy as little space as possible.
    Provides different types of algorithms listed below.
*/
class BoxArrangement {
public:
    // Arranging algorithm types.
    enum AlgorithmType {
        // Boxes' volume based sort and arrange order.
        VOLUME,
        SD
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
    // It does not copy boxes itself, just pointers. No data duplication.
    BoxArrangement (BoxStack boxes, AlgorithmType type);

    // Start arranging (with previously specified algorithm).
    void arrange ();

    // Print info about all stacks and all boxes in each stack.
    void printAll ();

    // Return formatted string with information about stacks.
    std::string getAllStacks ();

    // Return type of algorithm used.
    AlgorithmType getType ();

    // Return sum of biggest boxes' volumes.
    float getTotalVolume ();

    // Return number of stacks.
    unsigned int getSize ();

    // Return measured time.
    float getTime ();

private:
    // Sort all stored boxes by special criteria.
    void sort ();

    /// Different arranging algorithms.
    
    void arrangeFirstBest ();   //
    void arrangeBisect ();

    // All boxes.
    BoxStack mBoxes;

    // Separate stacks of boxes.
    StackGroup mStackGroup;

    // Type of algorithm used.
    AlgorithmType mType;

    // Elapsed time per algorithm run.
    float mTime = 0.f;
};

#endif

