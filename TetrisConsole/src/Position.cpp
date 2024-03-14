#include "Position.h"


Position::Position(int x, int y): x(x), y(y){}
Position::Position(){}

/**
 * surcharge de l opérateur += pour que quand on fasse cela ca change les coordonéées de l instance courante
 * @brief Position::operator +=
 * @param other
 * @return
 */
Position& Position::operator+=(const Position& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int x) {
    this->x = x;
}

void Position::setY(int y) {
    this->y = y;
}
