#include "Bag.h"
#include "directoryBrick/i.h"
#include <stdexcept>

Bag::Bag(){

    I i;
    listOfShapes.push_back(i);
}

/**
 * @brief Bag::nextShape
 * @return la référence de l objet Brick
 */
Brick& Bag::nextShape() {
    if (listOfShapes.size() > 0) {
        Brick* firstBrickPtr = &listOfShapes.front(); // Obtenir un pointeur vers la première brique
        listOfShapes.erase(listOfShapes.begin());
        return *firstBrickPtr;
    } else {

        throw std::out_of_range("Bag is Empty");
    }
}
