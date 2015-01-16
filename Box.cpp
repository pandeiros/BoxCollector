#include "Box.h"

Box::Box (const float width, const float height, const float depth)
    : mWidth (width), mHeight (height), mDepth (height) {
}

float Box::getWidth () {
    return mWidth;
}

float Box::getHeight () {
    return mHeight;
}

float Box::getDepth () {
    return mDepth;
}
