cmake_minimum_required (VERSION 3.18)

project (command_and_dominate)

set (CMAKE_BUILD_TYPE "DEBUG")
#set (CMAKE_BUILD_TYPE "RELEASE")


set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++20)

add_subdirectory (src)
add_subdirectory (thirdparty)
