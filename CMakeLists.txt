cmake_minimum_required(VERSION 3.28)
project(LiSI C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(LiSI
        functions.c
        functions.h
        main.c)
