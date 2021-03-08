cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(Romain)

include(cmake/functions.cmake)

add_subdirectory(functions)
add_subdirectory(main)

option(BTEST "build test?" ON)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()