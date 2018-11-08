cmake_minimum_required(VERSION 3.12)
project(EE312proj6_GoFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(EE312proj6_GoFish
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/EE312proj6_GoFish.cbp
        cmake-build-debug/EE312proj6_GoFish.exe
        cmake-build-debug/Makefile
        card.cpp
        card.h
        card_demo.cpp
        deck.cpp
        deck.h
        player.cpp
        player.h)
