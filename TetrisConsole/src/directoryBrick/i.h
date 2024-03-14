#ifndef I_H
#define I_H

#include "Brick.h"

class I : public Brick
{
public:
    I();
    virtual std::vector<Position> getPositionsTrue() override;
};

#endif // I_H
