cmake_minimum_required(VERSION 3.21)
project(arrangements)

set(CMAKE_CXX_STANDARD 20)

add_executable(arrangements main.cpp cmake-build-debug/permutation.cpp cmake-build-debug/permutation.h cmake-build-debug/tools.cpp cmake-build-debug/tools.h)
