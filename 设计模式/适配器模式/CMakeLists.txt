cmake_minimum_required(VERSION 3.15)
project(适配器模式)

add_compile_options(-std=c++11)

add_executable(ClassAdapter ClassAdapter.cpp)
add_executable(ObjectAdapter ObjectAdapter.cpp)
add_executable(Sequence Sequence.cpp)