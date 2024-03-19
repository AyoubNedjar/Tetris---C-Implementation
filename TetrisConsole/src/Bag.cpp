#include "Bag.h"
#include "directoryBrick/i.h"
#include "directoryBrick/j.h"
#include "directoryBrick/l.h"
#include "directoryBrick/s.h"
#include "directoryBrick/square.h"
#include "directoryBrick/t.h"
#include "directoryBrick/z.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Bag::Bag(){


    listOfShapes.push_back(std::make_unique<Square>());
     listOfShapes.push_back(std::make_unique<I>());
    listOfShapes.push_back(std::make_unique<Square>());
    listOfShapes.push_back(std::make_unique<Square>());
    listOfShapes.push_back(std::make_unique<Square>());

    listOfShapes.push_back(std::make_unique<S>());
    listOfShapes.push_back(std::make_unique<J>());

    listOfShapes.push_back(std::make_unique<Z>());
    listOfShapes.push_back(std::make_unique<T>());

    listOfShapes.push_back(std::make_unique<L>());

}

void Bag::shuffle()
{
    listOfShapes.push_back(std::make_unique<Square>());
    listOfShapes.push_back(std::make_unique<I>());

    listOfShapes.push_back(std::make_unique<S>());
    listOfShapes.push_back(std::make_unique<J>());

    listOfShapes.push_back(std::make_unique<Z>());
    listOfShapes.push_back(std::make_unique<T>());

    listOfShapes.push_back(std::make_unique<L>());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(listOfShapes.begin(), listOfShapes.end(), gen);
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
          shuffle();
          auto firstBrickPtr = std::move(listOfShapes.front());
          listOfShapes.erase(listOfShapes.begin());
          // Retourner le pointeur à la brique déplacée
          return firstBrickPtr;
      }
}
