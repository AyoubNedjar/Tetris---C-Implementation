#ifndef SQUARE_H
#define SQUARE_H

#include "Brick.h"

class Square : public Brick
{
public:
    Square();
    // virtual std::vector<Position> getPositionsTrue() override;
    const CaseType getType() const override;
    virtual void rotate(Rotation sens) override;
};

#endif // SQUARE_H
