cmake_minimum_required(VERSION 3.22)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)
include_directories(include)
include_directories(test)

# Set up global variables for build paths
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)

# Set up libraries
add_library(binaryNode ${INCLUDE_DIR}/tree/binaryTree/BinaryNode.hpp ${SRC_DIR}/tree/binaryTree/BinaryNode.cpp)
add_library(binaryTree ${INCLUDE_DIR}/tree/binaryTree/BinaryTree.hpp ${SRC_DIR}/tree/binaryTree/BinaryTree.cpp)
add_library(graph ${INCLUDE_DIR}/graph/Graph.hpp ${SRC_DIR}/graph/Graph.cpp)
add_library(avlTree ${INCLUDE_DIR}/tree/avlTree/AVLTree.hpp ${SRC_DIR}/tree/avlTree/AVLTree.cpp)
add_library(avlNode ${INCLUDE_DIR}/tree/avlTree/AVLNode.hpp ${SRC_DIR}/tree/avlTree/AVLNode.cpp)
add_library(quadTree ${INCLUDE_DIR}/tree/quadTree/QuadTree.hpp ${SRC_DIR}/tree/quadTree/QuadTree.cpp)

add_executable(dataStructures
        ${SRC_DIR}/tree/binaryTree/BinaryNode.cpp
        ${SRC_DIR}/tree/binaryTree/BinaryTree.cpp
        ${SRC_DIR}/tree/avlTree/AVLNode.cpp
        ${SRC_DIR}/tree/avlTree/AVLTree.cpp
        ${SRC_DIR}/graph/Graph.cpp
        ${SRC_DIR}/tree/quadTree/QuadTree.cpp
        main.cpp)

target_link_libraries(dataStructures stdc++ binaryNode binaryTree graph avlTree avlNode quadTree)
