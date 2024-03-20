#include "j.h"

J::J() {
    shapeMatrix =
        {{false ,false ,true  ,false},
         {false ,false ,true  ,false},
         {false ,true  ,true  ,false},
         {false ,false ,false ,false}};
    type = CaseType::SHAPE_J;
}

const CaseType J::getType() const
{
    return type;
}
