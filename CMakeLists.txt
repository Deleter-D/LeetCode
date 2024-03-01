cmake_minimum_required(VERSION 3.17)

project(Algorithm)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/executable)
add_compile_options(-g)

include_directories(utils)
add_subdirectory(01_Array)
add_subdirectory(02_LinkedList)
