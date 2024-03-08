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
    directoryBrick/i.h directoryBrick/i.cpp
    directoryBrick/square.h directoryBrick/square.cpp
    directoryBrick/t.h directoryBrick/t.cpp
    directoryBrick/j.h directoryBrick/j.cpp
    directoryBrick/l.h directoryBrick/l.cpp
    directoryBrick/z.h directoryBrick/z.cpp
    directoryBrick/s.h directoryBrick/s.cpp




)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
