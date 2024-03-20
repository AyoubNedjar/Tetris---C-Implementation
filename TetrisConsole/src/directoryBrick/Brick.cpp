#include "Brick.h"
#include <cstdlib>

Brick::Brick() : shapeMatrix() , center(), type() {}

std::vector<Position> Brick::getPositionsTrue() {

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

const CaseType Brick::getType()const{
    return type;
}
void Brick::transpose()
{
    for (int i = 0; i < shapeMatrix.size(); i++)
        for (int j = i; j < shapeMatrix.size(); j++)
            swap(shapeMatrix[i][j], shapeMatrix[j][i]);
}
void Brick::reverseColumns()
{
    for (int i = 0; i < shapeMatrix.size(); i++)
        for (int j = 0, k = shapeMatrix.size() - 1; j < k; j++, k--)
            swap(shapeMatrix[j][i], shapeMatrix[k][i]);
}

//Source : https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
void Brick::rotate(Rotation rotation){
    int size = shapeMatrix.size();
    switch(rotation){
    case Rotation::CLOCKWISE :
        for (int i = 0; i < size / 2; i++) {
            for (int j = i; j < size - i - 1; j++) {
                int temp = shapeMatrix[i][j];
                shapeMatrix[i][j] = shapeMatrix[size - 1 - j][i];
                shapeMatrix[size - 1 - j][i] = shapeMatrix[size - 1 - i][size - 1 - j];
                shapeMatrix[size - 1 - i][size - 1 - j] = shapeMatrix[j][size - 1 - i];
                shapeMatrix[j][size - 1 - i] = temp;
            }
        }

        break ;
    case Rotation::ANTI_CLOCKWISE :
        transpose();
        reverseColumns();
        break ;
    }
}

