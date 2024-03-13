#ifndef COMMONDATA_H
#define COMMONDATA_H


enum Direction{//faire une methode dans la classe position qui prend une direction et retourne une position
    LEFT,
    RIGHT,
    LOW,
};
enum Rotation{
   CLOCKWISE, ANTI_CLOCKWISE
};
enum State{
    PLAYING, LOST
};
enum CaseType{
    SHAPE_Z, SHAPE_L, SHAPE_SQUARE, SHAPE_T, SHAPE_I, SHAPE_J, SHAPE_S,NOT_OCCUPIED
};


#endif // COMMONDATA_H
