cmake_minimum_required(VERSION 3.4)
project(jocsOlimpicsObjectes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Inscripcio.cpp Inscripcio.h LlistaInscripcions.cpp LlistaInscripcions.h)
add_executable(jocsOlimpicsObjectes ${SOURCE_FILES})