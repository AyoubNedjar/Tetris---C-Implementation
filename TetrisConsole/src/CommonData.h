#ifndef COMMONDATA_H
#define COMMONDATA_H


enum Direction{//faire une methode dans la classe position qui prend une direction et retourne une position

    LEFT(1, -1),
    RIGHT(1, 0),
    LOW(1, 1)

    // Attributs pour les deltas
    const int deltaRow;
    const int deltaColumn;

    // Constructeur privé pour initialiser les attributs
    Direction(int deltaR, int deltaC) : deltaRow(deltaR), deltaColumn(deltaC);

    // Getters pour les deltas
    int getDeltaRow() const {
        return deltaRow;
    }

    int getDeltaColumn() const {
        return deltaColumn;
    }
}





















};
enum SensRotation{
   CLOCKWISE, ANTI_CLOCKWISE
};
enum State{
    PLAYING, LOST
};
enum CaseType{
    SHAPE_Z, SHAPE_L, SHAPE_SQUARE, SHAPE_T, SHAPE_I, SHAPE_J, SHAPE_S,NOT_OCCUPIED
};


#endif // COMMONDATA_H
