cmake_minimum_required(VERSION 3.15)
project(AVLtree C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(. DIR_SRCS)

add_executable(AVLtree ${DIR_SRCS})