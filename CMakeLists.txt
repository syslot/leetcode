cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 14)


add_subdirectory(leetcode)
add_subdirectory(swordoffer)

INCLUDE_DIRECTORIES(./)

SET(CMAKE_CXX_FLAGS -Wreturn-type -fsanitize=address)
#set(CMAKE_VERBOSE_MAKEFILE ON)


#include_directories('${CMAKE_SOURCE_DIR}')

