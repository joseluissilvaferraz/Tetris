cmake_minimum_required(VERSION 3.15)

project(Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Tetris
    src/main.cpp
    src/game.cpp
    src/board.cpp
    src/piece.cpp
)