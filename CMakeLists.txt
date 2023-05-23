cmake_minimum_required(VERSION 3.22)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set up Catch2
find_package(Catch2 REQUIRED)

# Add CTest
include(CTest)
include(Catch)
enable_testing()

# Set up global variables for build paths
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)

# Set up libraries
add_library(BINARY_NODE SHARED ${INCLUDE_DIR}/tree/binaryTree/BinaryNode.hpp ${SRC_DIR}/tree/binaryTree/BinaryNode.tpp)
add_library(BINARY_TREE SHARED ${INCLUDE_DIR}/tree/binaryTree/BinaryTree.hpp ${SRC_DIR}/tree/binaryTree/BinaryTree.tpp)
add_library(AVL_NODE SHARED ${INCLUDE_DIR}/tree/avlTree/AVLNode.hpp ${SRC_DIR}/tree/avlTree/AVLNode.tpp)
add_library(AVL_TREE SHARED ${INCLUDE_DIR}/tree/avlTree/AVLTree.hpp ${SRC_DIR}/tree/avlTree/AVLTree.tpp)
add_library(QUAD_NODE SHARED ${SRC_DIR}/tree/quadTree/QuadNode.cpp)
add_library(QUAD_TREE SHARED ${SRC_DIR}/tree/quadTree/QuadTree.cpp)
add_library(GRAPH_NODE SHARED ${INCLUDE_DIR}/graph/Node.hpp ${SRC_DIR}/graph/Node.tpp)
add_library(GRAPH_EGDE SHARED ${INCLUDE_DIR}/graph/Edge.hpp ${SRC_DIR}/graph/Edge.tpp)
add_library(GRAPH SHARED ${INCLUDE_DIR}/graph/Graph.hpp ${SRC_DIR}/graph/Graph.tpp)

# This property is used to specify the linker language to use for the target, becauese .tpp isn't by default 
set_target_properties(BINARY_NODE PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(BINARY_TREE PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(AVL_NODE PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(AVL_TREE PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(GRAPH_NODE PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(GRAPH_EGDE PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(GRAPH PROPERTIES LINKER_LANGUAGE CXX)


# Compile an executable file and link dependecies
add_executable(avltest ${TEST_DIR}/treeTest/avlTreeTest/test.cpp)
target_link_libraries(avltest PRIVATE stdc++ AVL_TREE)

add_executable(graphAddingTest ${TEST_DIR}/graphTest/addNodeTest.cpp)
target_link_libraries(graphAddingTest PRIVATE stdc++ GRAPH)

add_executable(graphBFSTest ${TEST_DIR}/graphTest/bfsTest.cpp)
target_link_libraries(graphBFSTest PRIVATE stdc++ GRAPH)

add_executable(graphDFSTest ${TEST_DIR}/graphTest/dfsTest.cpp)
target_link_libraries(graphBFSTest PRIVATE stdc++ GRAPH)

add_executable(graphDijkstraTest ${TEST_DIR}/graphTest/dijkstraTest.cpp)
target_link_libraries(graphDijkstraTest PRIVATE stdc++ GRAPH)

add_executable(graphFloydWarshallTest ${TEST_DIR}/graphTest/floydWarshallTest.cpp)
target_link_libraries(graphFloydWarshallTest PRIVATE stdc++ GRAPH)


# Add a executable file as a test
add_test(NAME AVL_TREE_TEST COMMAND avltest Catch2)
add_test(NAME GRAPH_TEST COMMAND graphAddingTest Catch2)