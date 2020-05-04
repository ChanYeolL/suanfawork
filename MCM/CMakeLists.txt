cmake_minimum_required(VERSION 3.15)
project(MCM C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(. DIR_SRCS)

add_executable(MCM ${DIR_SRCS})
