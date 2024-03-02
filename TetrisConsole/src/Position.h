#ifndef POSITION_H
#define POSITION_H


#include "CommonData.h"
class Position
{
    int x;
    int y;
public:
    Position(int x,int y);

    int getX() const;
    int getY() const;

    Position getPositionFromDirection(Direction dir);

    // Méthodes pour modifier les attributs (setters)
    void setX(int value);
    void setY(int value);
};

#endif // POSITION_H
