#ifndef POSITION_H
#define POSITION_H


#include "CommonData.h"
class Position
{
    int x;
    int y;
public:

    Position();//je crée cette position pour que game commence avc une position par defaut de la brique
    Position(int x,int y);

    Position& operator+=(const Position& other);
    int getX() const;
    int getY() const;

    Position getPositionFromDirection(Direction dir);

    // Méthodes pour modifier les attributs (setters)
    void setX(int value);
    void setY(int value);
};

#endif // POSITION_H
