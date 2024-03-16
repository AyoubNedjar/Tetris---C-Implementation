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

Position Position::getPositionFromDirection(Direction dir)
{switch (dir) {
    case LEFT:
        return Position(- 1, 0);
        break;
    case RIGHT:
        return Position(1, 0);
        break;
    case DOWN:
        return Position(0, 1);
        break;
    default:
        return *this;
        break;
    }

}

void Position::setX(int x) {
    this->x = x;
}

void Position::setY(int y) {
    this->y = y;
}
