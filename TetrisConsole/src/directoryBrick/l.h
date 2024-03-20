#ifndef L_H
#define L_H

#include "Brick.h"

class L : public Brick
{
public:
    L();
    // virtual std::vector<Position> getPositionsTrue() override;
    const CaseType getType() const;
};

#endif // L_H
