/**
    @Title:   [AAL] - "Orthodox Box Collector"
    @Author:  Pawe³ Kaczyñski

    Warsaw University of Technology
    Faculty of Electronics and Information Technology

*/

#ifndef _BOX_
#define _BOX_

/**
    Represents a single box. Contains width, length, height and volume attributes.
*/
class Box {
public:
    ~Box () {
    };

    // Constructor with size parameters
    // \params float : Width, height and length of the box.
    Box (const float width, const float length, const float depth);

    /// Getters

    float getWidth ();
    float getHeight ();
    float getLength ();
    float getVolume ();

private:
    /// Box parameters

    float mWidth = 0.f;
    float mHeight = 0.f;
    float mLength = 0.f;
    float mVolume = 0.f;
};

#endif _BOX_

