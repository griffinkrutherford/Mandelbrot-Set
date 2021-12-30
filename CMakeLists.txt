cmake_minimum_required(VERSION 3.17)
project(Mandelbrot_Set)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mandelbrot_Set main.cpp grifcomplex.cpp mandelbrot.cpp mandelbrotgrid.cpp)