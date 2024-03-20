#ifndef S_H
#define S_H

#include "Brick.h"

class S : public Brick
{
public:
    S();
    // virtual std::vector<Position> getPositionsTrue() override;
    const CaseType getType() const;
};

#endif // S_H
