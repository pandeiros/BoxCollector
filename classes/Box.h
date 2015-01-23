/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Paweł Kaczyński

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _BOX_
#define _BOX_

#include <iostream>
#include <iomanip>
#include <algorithm>

/**
    Represents a single box. Contains width, length, height and volume attributes.
*/
class Box {
public:
    // Global id to distribute between boxes.
    static unsigned long GLOBAL_ID;

    ~Box () {
    };

    // Constructor with size parameters
    // \params float : Length, width and height of the box.
    Box (const float length, const float width, const float depth);

    // Compare two boxes and check if the one given in parameter can contain the other one inside.
    bool check (Box * biggerBox);

    /// Getters

    float getWidth ();
    float getHeight ();
    float getLength ();
    float getVolume () const;
    unsigned long getID ();

private:
    // Set box sizes in that order: length >= width >= height.
    void normalize ();

    // Box unique id.
    unsigned long mID;

    /// Box parameters

    float mLength = 0.f;
    float mWidth = 0.f;
    float mHeight = 0.f;
    float mVolume = 0.f;

    // Overloaded output stream operator for displaying information about boxes.
    friend std::ostream & operator<< (std::ostream & output, Box & box) {
        output << std::right << std::setw (12) << box.getID() << " | ";
        output << std::left << std::setw (10) << box.getWidth () << " | ";
        output << std::left << std::setw (10) << box.getLength () << " | ";
        output << std::left << std::setw (10) << box.getHeight () << " | ";
        output << std::left << std::setw (14) << box.getVolume () << "|\n";

        return output;
    }
};

#endif _BOX_

