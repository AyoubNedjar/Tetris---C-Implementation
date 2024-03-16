#ifndef L_H
#define L_H

#include "Brick.h"

class L : public Brick
{
public:
    L();
    virtual std::vector<Position> getPositionsTrue() override;
    virtual const CaseType getType() const override;
};

#endif // L_H
