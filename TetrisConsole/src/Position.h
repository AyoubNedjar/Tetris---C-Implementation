#ifndef POSITION_H
#define POSITION_H


class Position
{
    int x;
    int y;
public:
    Position(int x,int y);

    int getX() const;
    int getY() const;

    // Méthodes pour modifier les attributs (setters)
    void setX(int value);
    void setY(int value);
};

#endif // POSITION_H
