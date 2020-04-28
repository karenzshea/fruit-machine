cmake_minimum_required(VERSION 3.9)

project(fruit-machine LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for ycm
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -pedantic -std=c++17")

add_subdirectory(library)
add_subdirectory(app)
