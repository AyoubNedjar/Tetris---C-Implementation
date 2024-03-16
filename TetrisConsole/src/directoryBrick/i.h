#ifndef I_H
#define I_H

#include "Brick.h"

class I : public Brick
{
public:
    I();
    virtual std::vector<Position> getPositionsTrue() override;
    virtual const CaseType getType() const override;
};

#endif // I_H
