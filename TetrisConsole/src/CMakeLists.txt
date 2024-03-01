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


)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
