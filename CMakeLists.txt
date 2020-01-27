cmake_minimum_required(VERSION 3.15)
project(ChainOfResponsiblity490)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChainOfResponsiblity490 main.cpp DigApp.cpp DigApp.h Menu.cpp
        Menu.h Material.h diamondHandler.h dirtHandler.h grassHandler.h
        HandleDig.cpp HandleDig.h stoneHandler.h Digger.cpp Digger.h Level.cpp Level.h)