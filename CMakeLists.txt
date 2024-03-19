cmake_minimum_required(VERSION 3.17)

project(Algorithm)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/executable)
add_compile_options(-g)

include_directories(utils)
add_subdirectory(01_Array)
add_subdirectory(02_LinkedList)
add_subdirectory(03_HashTable)
add_subdirectory(04_String)
add_subdirectory(05_StackAndQueue)
add_subdirectory(06_BinaryTree)
