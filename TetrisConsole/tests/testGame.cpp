#include <catch2/catch_test_macros.hpp>
#include "../src/Model/Game.h"

TEST_CASE( "Test of Game") {

    SECTION("Test moveBrick method") {
        Game game;
        int initialScore = game.getScore();
        int initialNbLigneComplete = game.getNbLigneComplete();
        game.moveBrick(Direction::DOWN, false);
        REQUIRE(game.getScore() == initialScore);
        REQUIRE(game.getNbLigneComplete() == initialNbLigneComplete);
    }

    SECTION("Test drop method"){

    }
}
