#ifndef BRICK_H
#define BRICK_H

#include "..\Position.h"

#include <vector>
//#include "..\CommonData.h"

class Brick
{
protected:
    std::vector<std::vector<bool>> shapeMatrix;
    Position center;
public:
    Brick();
    virtual std::vector<Position> getPositionsTrue() = 0;
    //virtual void rotate(Rotation rotation);
};

#endif // BRICK_H
