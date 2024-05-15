cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


add_executable(ProjectStructure
    main.cpp
    Model/CommonData.h          Controller/Controller.cpp

    Model/Position.h            Model/Position.cpp
    Observer/Observer.h
    Observer/Observable.h       Observer/Observable.cpp

    Model/CheckRules.h          Model/CheckRules.cpp
    Model/Board.h               Model/Board.cpp
    Model/Bag.h                 Model/Bag.cpp
    View/View.h                 View/View.cpp
    Model/Game.h                Model/Game.cpp

    directoryBrick/Brick.h      directoryBrick/Brick.cpp
    directoryBrick/i.h          directoryBrick/i.cpp
    directoryBrick/square.h     directoryBrick/square.cpp
    directoryBrick/t.h          directoryBrick/t.cpp
    directoryBrick/j.h          directoryBrick/j.cpp
    directoryBrick/l.h          directoryBrick/l.cpp
    directoryBrick/z.h          directoryBrick/z.cpp
    directoryBrick/s.h          directoryBrick/s.cpp
    Controller/Controller.h     Controller/Controller.cpp


    Ui/mainwindow.h Ui/mainwindow.cpp Ui/mainwindow.ui
    Ui/uicontroller.h Ui/uicontroller.cpp
)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets )
find_package( Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets )
target_link_libraries(ProjectStructure PRIVATE
       Qt${QT_VERSION_MAJOR}::Widgets)
