#include "l.h"

L::L() {
    shapeMatrix =
        {{false ,true  ,false ,false},
         {false ,true  ,false ,false},
         {false ,true  ,true  ,false},
         {false ,false ,false ,false}};
    type = CaseType::SHAPE_L;
}
const CaseType L::getType() const
{
    return type;
}
