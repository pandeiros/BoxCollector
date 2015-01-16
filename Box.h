#ifndef _BOX_
#define _BOX_

/**
    Represents a single box. Contains width, height and depth.
*/
class Box {
public:
    Box () {
    };
    ~Box () {
    };

    // Constructor with size parameters
    // \params float : Width, height and depth of the box.
    Box (const float width, const float height, const float depth);

    /// Getters

    float getWidth ();
    float getHeight ();
    float getDepth ();

private:
    // Box parameters
    float mWidth = 0.f;
    float mHeight = 0.f;
    float mDepth = 0.f;
};

#endif _BOX_

