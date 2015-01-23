/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _COLLECTION_
#define _COLLECTION_

#include <vector>
#include <iomanip>
#include <iostream>
#include "Box.h"
#include "BoxArrangement.h"

/**
    Collection of boxes. Contains also BoxArrangement object for holding current box
*/
class Collection {
public:
    // Container for Boxes.
    typedef std::vector<Box*> Boxes;

    Collection () {
    };
    ~Collection ();

    // Prints information about all boxes in Collection.
    void printAll ();

    // Generate random collection of boxes.
    // \param unsigned int number : Number of boxes to generate.
    // \param (opt) float max : Additional generator parameter - max box size in one axis.
    // \param (opt) unsigned int precision : Floating point precision.
    void generateRandomData (unsigned int number, unsigned int max = 1, unsigned int precision = 2);

    /// Getters

    Boxes * getBoxes ();    // Return pointer to Box container.
    BoxArrangement * getBoxArrangement ();  // Return pointer to arranged boxes.

    /// Setters

    void setBoxArrangement (BoxArrangement * boxArrangement);   // Set new box arrangement pointer.
    void setBoxes (Boxes & boxes);  // Set new collection of boxes.

private:
    // Wipe out current Box container.
    void deleteBoxes ();

    // Box collection;
    Boxes mBoxes;

    // Arranged boxes.
    BoxArrangement * mBoxArrangement;
};

#endif

