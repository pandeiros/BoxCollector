/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#include "Box.h"

unsigned long Box::GLOBAL_ID = 0;

bool Box::check (Box * biggerBox) {
    if (this->mHeight < biggerBox->mHeight &&
        this->mWidth < biggerBox->mWidth &&
        this->mLength < biggerBox->mLength)
        return true;
    else
        return false;
}

Box::Box (const float length, const float width, const float height)
    : mWidth (width), mHeight (height), mLength (length), 
    mVolume (width * length * height), mID (GLOBAL_ID++) {

    normalize ();
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

float Box::getVolume () const {
    return mVolume;
}

unsigned long Box::getID () {
    return mID;
}

void Box::normalize () {
    float sizes[3] = {mLength, mWidth, mHeight};
    std::sort (sizes, sizes + 3);
    mHeight = sizes[0];
    mWidth = sizes[1];
    mLength = sizes[2];
}

