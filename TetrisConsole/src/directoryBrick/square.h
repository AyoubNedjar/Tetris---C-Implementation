#ifndef SQUARE_H
#define SQUARE_H

#include "Brick.h"

class Square : public Brick
{
public:
    Square();
    virtual std::vector<Position> getPositionsTrue() override;
    virtual const CaseType getType() const override;
};

#endif // SQUARE_H
