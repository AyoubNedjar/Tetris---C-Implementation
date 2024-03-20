#include "square.h"

Square::Square() {
    shapeMatrix =
        {{false ,false ,false ,false},
         {false ,true  ,true  ,false},
         {false ,true  ,true  ,false},
         {false ,false ,false ,false}};
    type = CaseType::SHAPE_SQUARE;
}

const CaseType Square::getType() const
{
    return type;
}

void Square::rotate(Rotation sens){
    //Ne va rien faire .
}
