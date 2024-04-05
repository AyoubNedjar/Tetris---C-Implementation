#ifndef BAG_H
#define BAG_H


#include "../directoryBrick/Brick.h"
#include <memory>

class Bag
{
private :

    std::vector<std::unique_ptr<Brick>> listOfShapes;
public:
    Bag();
    void shuffle();
    std::unique_ptr<Brick> nextShape();

};

#endif // BAG_H
