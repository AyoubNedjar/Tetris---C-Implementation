cmake_minimum_required(VERSION 3.5)


add_executable(ProjectStructure
    main.cpp
    MyClass.h
    MyClass.cpp
    CommonData.h
    CommonData.cpp
    Position.h Position.cpp
    Observer.h
    Observable.h Observable.cpp
    directoryBrick/Brick.h directoryBrick/Brick.cpp
    CheckRules.h CheckRules.cpp
    Board.h Board.cpp
    Bag.h Bag.cpp
    View.h View.cpp
    Game.h Game.cpp




)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
