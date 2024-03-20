#include "i.h"

I::I():Brick() {
    shapeMatrix =
        {{false ,false ,true ,false},
         {false ,false ,true ,false},
         {false ,false ,true ,false},
         {false ,false ,true ,false}};

     type = CaseType::SHAPE_I;
}

const CaseType I::getType() const
{
    return type;
}
