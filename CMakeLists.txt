cmake_minimum_required(VERSION 3.17.5)
set(project "Praktika")
project(${project})
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_subdirectory(Objects)
add_subdirectory(Control)
add_subdirectory(Mechanichs)

set(${project}_SOURCES
        main.cpp)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST} main.cpp Objects/Building.cpp Objects/Building.h Control/Control.cpp Control/Control.h Mechanichs/Mechanichs.cpp Mechanichs/Mechanichs.h)

target_link_libraries(${project} sfml-graphics)



