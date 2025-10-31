cmake_minimum_required(VERSION 3.10)
project (luablocks CXX)

set (CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

FILE(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)
