cmake_minimum_required(VERSION 3.17)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/executable)
add_compile_options(-g)

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(01_Array)
add_subdirectory(02_LinkedList)
add_subdirectory(03_HashTable)
add_subdirectory(04_String)
add_subdirectory(05_StackAndQueue)
add_subdirectory(06_BinaryTree)
