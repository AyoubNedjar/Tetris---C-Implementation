#include "i.h"

I::I():Brick() {
    shapeMatrix =
        {{false ,false ,true ,false},
         {false ,false ,true ,false},
         {false ,false ,true ,false},
         {false ,false ,true ,false}};

     type = CaseType::SHAPE_I;
}



/**
 * cette methode va nous renvoyer les positions des true de la brique
 * @brief I::getPositionsTrue
 * @return
 */
std::vector<Position> I::getPositionsTrue() {

    std::vector<Position> truePositions;

    for (int  i = 0; i < shapeMatrix.size(); ++i) {
        for (int j = 0; j < shapeMatrix[i].size(); ++j) {
            if (shapeMatrix[i][j]) {
                truePositions.push_back(Position(i, j));
            }
        }
    }
    return truePositions;
}

const CaseType I::getType() const
{
    return type;
}
