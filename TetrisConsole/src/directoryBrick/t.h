#ifndef T_H
#define T_H

#include "Brick.h"

class T : public Brick
{
public:
    T();
    virtual std::vector<Position> getPositionsTrue() override;
    virtual const CaseType getType() const override;
};

#endif // T_H
