#include "t.h"

T::T(){
    shapeMatrix =
        {{false ,true ,true,true},
         {false ,false ,true,false},
         {false ,false ,false ,false},
         {false ,false ,false ,false}};
    type = CaseType::SHAPE_T;
}

const CaseType T::getType() const
{
    return type;
}
