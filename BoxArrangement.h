#ifndef _BOX_ARRANGEMENT_
#define _BOX_ARRANGEMENT_

#include <vector>
#include "Box.h"

/**

*/
class BoxArrangement {
public:
    // Group of boxes stacked together.
    typedef std::vector<Box*> BoxStack;

    // Separate stacks of boxes.
    typedef std::vector<BoxStack> StackGroup;

    BoxArrangement () {
    };
    ~BoxArrangement () {
    };

private:
    StackGroup mStackGroup;
};

#endif

