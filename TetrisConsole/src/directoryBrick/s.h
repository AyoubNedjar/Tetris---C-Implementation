#ifndef S_H
#define S_H

#include "Brick.h"

class S : public Brick
{
public:
    S();
    virtual std::vector<Position> getPositionsTrue() override;
    virtual const CaseType getType() const override;
};

#endif // S_H
