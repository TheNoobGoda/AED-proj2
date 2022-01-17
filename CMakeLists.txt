cmake_minimum_required(VERSION 3.20)
project(AED_proj2)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE CLASSES RELATIVE ${CMAKE_SOURCE_DIR} "Source/*.cpp" "Source/*.h")

add_executable(AED_proj2 main.cpp ${CLASSES})
