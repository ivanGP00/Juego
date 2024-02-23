cmake_minimum_required(VERSION 3.27)
project(Juego2)

set(CMAKE_CXX_STANDARD 14)

include_directories(Enemy)
include_directories(Player)

add_executable(Juego2
        Enemy/Enemy.cpp
        Enemy/Enemy.h
        Player/Player.cpp
        Player/Player.h
        main.cpp
        Character/Character.h
        Character/Character.cpp)
