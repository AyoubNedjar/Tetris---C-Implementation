#ifndef BRICK_H
#define BRICK_H

#include "..\Position.h"

#include <vector>
//#include "..\CommonData.h"

class Brick
{
private :
    virtual void transpose();
    virtual void reverseColumns();

protected:
    std::vector<std::vector<bool>> shapeMatrix;
    Position center;
    CaseType type;

public:
    Brick();
    virtual std::vector<Position> getPositionsTrue();
    virtual const CaseType getType() const ;
    virtual void rotate(Rotation rotation);
};

#endif // BRICK_H
