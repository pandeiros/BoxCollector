#ifndef _COLLECTION_
#define _COLLECTION_

#include <vector>
#include "Box.h"
#include "BoxArrangement.h"

/**

*/
class Collection {
public:
    // Container for Boxes.
    typedef std::vector<Box*> Boxes;

    Collection () {
    };
    ~Collection () {
    };

    /// Getters

    Boxes * getBoxes ();    // Return pointer to Box container.
    BoxArrangement * getBoxArrangement ();  // Return pointer to arranged boxes.

private:
    // Box collection;
    Boxes mBoxes;

    // Arranged boxes.
    BoxArrangement mBoxArrangement;
};

#endif

