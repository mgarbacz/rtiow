# CMake Build Configuration for rtiow

cmake_minimum_required(VERSION 3.5)

project(rtiow LANGUAGES CXX)

# Set to C++11
set ( CMAKE_CXX_STANDARD          11 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS        OFF )

add_executable(main main.cc)
