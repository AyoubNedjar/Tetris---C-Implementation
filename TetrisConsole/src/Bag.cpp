#include "Bag.h"
#include "directoryBrick/i.h"
#include <stdexcept>

Bag::Bag(){

      listOfShapes.push_back(std::make_unique<I>());
}

/**
 * @brief Bag::nextShape
 * @return la référence de l objet Brick
 */
std::unique_ptr<Brick> Bag::nextShape() {
      if (!listOfShapes.empty()) {
          // Déplacer le pointeur de la première brique
          auto firstBrickPtr = std::move(listOfShapes.front());
          listOfShapes.erase(listOfShapes.begin());
          // Retourner le pointeur à la brique déplacée
          return firstBrickPtr;
      } else {
          throw std::out_of_range("Bag is Empty");
      }
}
