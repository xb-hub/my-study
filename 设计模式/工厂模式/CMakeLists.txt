cmake_minimum_required(VERSION 3.15)
project(工厂模式)

add_compile_options(-std=c++11)

add_executable(SimpleFactory SimpleFactory.cpp)
add_executable(Factory Factory.cpp)
add_executable(AbstractFactory AbstractFactory.cpp)