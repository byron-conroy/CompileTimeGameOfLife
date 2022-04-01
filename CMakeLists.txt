cmake_minimum_required(VERSION 3.21)
project(GOL)

set(CMAKE_CXX_STANDARD 17)


if( WIN32 )
    add_compile_options(-W3 -WX)

    #improve diagnostic messages
    add_compile_options(/diagnostics:caret)

    #By default MSVC terminates constexpr evaluation after 100,000 steps, I bumped it up a bit
    add_compile_options(/constexpr:steps5000000)
endif ()

add_executable(
    GameOfLife
    GameOfLife.cpp
    GameOfLife/Constants.h
    GameOfLife/Printer.h
    GameOfLife/State.h
    GameOfLife/RecursiveStateProcessor.h
)
