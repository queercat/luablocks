cmake_minimum_required(VERSION 3.10)
project (luablocks CXX)

FILE(GLOB SOURCES src/*.hpp src/*.h src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib )
