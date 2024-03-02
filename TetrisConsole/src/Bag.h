#ifndef BAG_H
#define BAG_H


#include "directoryBrick/Brick.h"

class Bag
{
public:
    Bag();
    void shuffle();
    Brick nextShape();

};

#endif // BAG_H
