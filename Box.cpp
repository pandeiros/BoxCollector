/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "Box.h"

Box::Box (const float width, const float length, const float height)
    : mWidth (width), mHeight (height), mLength (length), mVolume (width * length * height) {
}

float Box::getWidth () {
    return mWidth;
}

float Box::getHeight () {
    return mHeight;
}

float Box::getLength () {
    return mLength;
}

float Box::getVolume () {
    return mVolume;
}
