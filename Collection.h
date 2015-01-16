#ifndef _COLLECTION_
#define _COLLECTION_

#include <vector>
#include "Box.h"

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

private:
    // Box collection;
    Boxes mBoxes;
};

#endif

