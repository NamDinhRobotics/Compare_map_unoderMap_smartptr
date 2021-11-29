cmake_minimum_required(VERSION 3.20)
project(smartptr)

set(CMAKE_CXX_STANDARD 14)

add_executable(smartptr smart_ptr.cpp)
add_executable(map compare_map_unodermap.cpp)
