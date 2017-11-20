cmake_minimum_required(VERSION 3.8)
project(pr4_eedd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Diccionario.h Diccionario.cpp Palabra.h Palabra.cpp Sucesor.h Sucesor.cpp)
add_executable(pr4_eedd ${SOURCE_FILES})