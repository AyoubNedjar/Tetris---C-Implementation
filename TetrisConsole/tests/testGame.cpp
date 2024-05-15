#include <catch2/catch_test_macros.hpp>
#include "../src/Model/Game.h"
#include "../src/directoryBrick/square.h"

TEST_CASE( "Test of Game") {

    SECTION("Test moveBrick method") {
        Game game;
        int initialScore = game.getScore();
        int initialNbLigneComplete = game.getBoard().getCountCompleteslines();
        game.moveBrick(Direction::DOWN, false);
        REQUIRE(game.getScore() == initialScore);
        REQUIRE(game.getBoard().getCountCompleteslines() == initialNbLigneComplete); // The score didn't change because it's a move not a drop .
    }
    SECTION("Test drop method"){
        Game game;
        //Default board setting .
        //Height == 20 .
        //Width == 15 .
        std::unique_ptr<Brick> currentBrick = std::make_unique<Square>();
        std::vector<Position> listOfCurrentPositions = currentBrick->getPositionsTrue();
        game.getScore();
        game.drop();
        REQUIRE(game.getScore() == (40 * 0 + game.getBoard().getHeight()-2)* 1); // getHeight-2 because height of square is 2 .
    }
}
