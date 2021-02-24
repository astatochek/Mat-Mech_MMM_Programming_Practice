cmake_minimum_required(VERSION 3.17)
project(sorting_library) # ну так он у меня назывался

set(CMAKE_CXX_STANDARD 14)

add_executable(sorting_library main.cpp qsort.cpp qsort.h random_sort.cpp random_sort.h min.cpp min.h insertion_sort.cpp insertion_sort.h)
