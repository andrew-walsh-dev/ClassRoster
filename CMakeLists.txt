cmake_minimum_required(VERSION 3.19)
project(ClassRoster)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ClassRoster
        degree.h
        main.cpp
        roster.cpp
        roster.h
        student.cpp
        student.h)
