cmake_minimum_required(VERSION 3.23)
project(dataStructures)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(TreeTAD
        src/tree/binaryTree/BinaryNode.cpp
        src/tree/binaryTree/BinaryNode.hpp
        src/tree/binaryTree/BinaryTree.cpp
        src/tree/binaryTree/BinaryTree.hpp
        src/graph/Graph.hpp 
        src/graph/Graph.cpp
        src/tree/avlTree/AVLTree.hpp
        src/tree/avlTree/AVLTree.cpp
        src/tree/quadTree/QuadTree.hpp
        src/tree/quadTree/QuadTree.cpp
        src/main.cpp)
