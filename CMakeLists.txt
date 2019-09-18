cmake_minimum_required(VERSION 3.14)
project(heap)

set(CMAKE_CXX_STANDARD 17)

add_executable(heap main.cpp PriorityQueue/PriorityQueue.cpp PriorityQueue/PriorityQueue.h)