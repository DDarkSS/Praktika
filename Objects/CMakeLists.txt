cmake_minimum_required(VERSION 3.17.5)

set(project "Building")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        Building.cpp
        Trajectory.cpp
        Resource.cpp)

set(${project}_HEADERS
        Building.h
        Trajectory.h
        Resource.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST} Trajectory.cpp Resource.cpp Resource.h)