cmake_minimum_required(VERSION 3.23)
project (VectorC C)

set(CMAKE_C_STANDARD 99)

add_executable(VectorC main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)
