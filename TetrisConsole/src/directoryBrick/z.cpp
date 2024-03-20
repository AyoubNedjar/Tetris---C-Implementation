#include "z.h"

Z::Z() {
    shapeMatrix =
        {{false ,false ,false ,false},
         {false ,true  ,true  ,false},
         {false ,false ,true  ,true },
         {false ,false ,false ,false}};
    type = CaseType::SHAPE_Z;
}
const CaseType Z::getType() const
{
    return type;
}
