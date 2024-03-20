#include "s.h"

S::S() {
    shapeMatrix =
        {{false ,false ,false ,false},
         {false ,true  ,true  ,false},
         {true  ,true  ,false ,false},
         {false ,false ,false ,false}};
    type = CaseType::SHAPE_S;
}
const CaseType S::getType() const
{
    return type;
}
