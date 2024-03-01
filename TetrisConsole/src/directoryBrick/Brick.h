#ifndef BRICK_H
#define BRICK_H

#include "..\Position.h"

#include <vector>
#include "..\CommonData.h"

class Brick
{
public:
    Brick();
    virtual void rotate(Rotation rotation)

protected://car on va l utiliser dans les classes filles
    std::vector<std::vector<bool>> shapeMatrix;
    Position center;
};

#endif // BRICK_H
