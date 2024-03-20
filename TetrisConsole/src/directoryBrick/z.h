#ifndef Z_H
#define Z_H

#include "Brick.h"

class Z : public Brick
{
public:
    Z();
    // virtual std::vector<Position> getPositionsTrue() override;
    const CaseType getType() const;
};

#endif // Z_H
