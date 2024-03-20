#ifndef J_H
#define J_H

#include "Brick.h"

class J : public Brick
{
public:
    J();
    // virtual std::vector<Position> getPositionsTrue() override;
    const CaseType getType() const;
};

#endif // J_H
