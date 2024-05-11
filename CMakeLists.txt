cmake_minimum_required(VERSION 3.10)
project(hBuffer VERSION 1.0)

# Define library
add_library(hBuffer)

# Add include directory
target_include_directories(hBuffer
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add source files
add_subdirectory(src)