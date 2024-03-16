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

/**
 * cette methode va nous renvoyer les positions des true de la brique
 * @brief I::getPositionsTrue
 * @return
 */
std::vector<Position> L::getPositionsTrue() {

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
