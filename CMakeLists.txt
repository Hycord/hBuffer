cmake_minimum_required(VERSION 3.28)
project(hBuffer)
include_directories(include)
add_library(hBuffer src/hBuffer.cpp include/hBuffer.h)