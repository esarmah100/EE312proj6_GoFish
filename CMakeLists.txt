cmake_minimum_required(VERSION 3.12)
project(EE312proj6_GoFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EE312proj6_GoFish
        card.cpp
        card.h
        card_demo.cpp
        deck.h
        player.h)
