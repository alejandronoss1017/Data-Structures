cmake_minimum_required(VERSION 3.22)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Configuración de variables globales para rutas de compilación
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)

# Configuración de librerías y ejecutables
add_library(binaryNode ${INCLUDE_DIR}/tree/binaryTree/BinaryNode.hpp ${SRC_DIR}/tree/binaryTree/BinaryNode.cpp)
add_library(binaryTree ${INCLUDE_DIR}/tree/binaryTree/BinaryTree.hpp ${SRC_DIR}/tree/binaryTree/BinaryTree.cpp)
add_library(graph ${INCLUDE_DIR}/graph/Graph.hpp ${SRC_DIR}/graph/Graph.cpp)
add_library(avlTree ${INCLUDE_DIR}/tree/avlTree/AVLTree.hpp ${SRC_DIR}/tree/avlTree/AVLTree.cpp)
#add_library(avlNode ${INCLUDE_DIR}/tree/avlTree/AVLNode.hpp ${SRC_DIR}/tree/avlTree/AVLNode.cpp)
add_library(quadTree ${INCLUDE_DIR}/tree/quadTree/QuadTree.hpp ${SRC_DIR}/tree/quadTree/QuadTree.cpp)


add_executable(graphTest ${TEST_DIR}/graphTest/test.cpp)
target_link_libraries(graphTest PRIVATE graph)

add_executable(avlTreeTest ${TEST_DIR}/treeTest/avlTreeTest/test.cpp)
target_link_libraries(avlTreeTest PRIVATE avlTree)

add_executable(binaryTreeTest ${TEST_DIR}/treeTest/binaryTreeTest/test.cpp)
target_link_libraries(binaryTreeTest PRIVATE binaryTree)

add_executable(quadTreeTest ${TEST_DIR}/treeTest/quadTreeTest/test.cpp)
target_link_libraries(quadTreeTest PRIVATE quadTree)

add_executable(main main.cpp ${INCLUDE_DIR}/tree/binaryTree/BinaryTree.hpp)
target_link_libraries(main PRIVATE binaryTree)

# add_subdirectory(src)
# add_subdirectory(test)

# include_directories(src)

# add_executable(TreeTAD
#         src/tree/binaryTree/BinaryNode.cpp
#         include/tree/binaryTree/BinaryNode.hpp
#         src/tree/binaryTree/BinaryTree.cpp
#         include/tree/binaryTree/BinaryTree.hpp
#         include/graph/Graph.hpp
#         src/graph/Graph.cpp
#         include/tree/avlTree/AVLTree.hpp
#         src/tree/avlTree/AVLTree.cpp
#         include/tree/quadTree/QuadTree.hpp
#         src/tree/quadTree/QuadTree.cpp
#         src/main.cpp)