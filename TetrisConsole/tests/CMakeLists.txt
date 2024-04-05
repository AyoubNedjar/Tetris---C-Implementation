cmake_minimum_required(VERSION 3.5)

add_executable(ProjectStructureTests
    testGame.cpp
    ../src/Model/CommonData.h          ../src/Controller/Controller.cpp

    ../src/Model/Position.h            ../src/Model/Position.cpp
    ../src/Observer/Observer.h
    ../src/Observer/Observable.h       ../src/Observer/Observable.cpp

    ../src/Model/CheckRules.h          ../src/Model/CheckRules.cpp
    ../src/Model/Board.h               ../src/Model/Board.cpp
    ../src/Model/Bag.h                 ../src/Model/Bag.cpp
    ../src/View/View.h                 ../src/View/View.cpp
    ../src/Model/Game.h                ../src/Model/Game.cpp

    ../src/directoryBrick/Brick.h      ../src/directoryBrick/Brick.cpp
    ../src/directoryBrick/i.h          ../src/directoryBrick/i.cpp
    ../src/directoryBrick/square.h     ../src/directoryBrick/square.cpp
    ../src/directoryBrick/t.h          ../src/directoryBrick/t.cpp
    ../src/directoryBrick/j.h          ../src/directoryBrick/j.cpp
    ../src/directoryBrick/l.h          ../src/directoryBrick/l.cpp
    ../src/directoryBrick/z.h          ../src/directoryBrick/z.cpp
    ../src/directoryBrick/s.h          ../src/directoryBrick/s.cpp
    ../src/Controller/Controller.h     ../src/Controller/Controller.cpp
)
target_include_directories(ProjectStructureTests PRIVATE
    ../src
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

target_link_libraries(ProjectStructureTests Catch2::Catch2WithMain)
