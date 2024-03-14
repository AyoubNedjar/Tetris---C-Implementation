#ifndef BAG_H
#define BAG_H


#include "directoryBrick/Brick.h"

class Bag
{
private :
    std::vector<Brick> listOfShapes;
public:
    Bag();
    void shuffle();
    Brick& nextShape();

};

#endif // BAG_H
