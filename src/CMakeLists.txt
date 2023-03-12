# Add all header files in the include folder to the project
file(GLOB INCLUDE_FILES include/*.hpp)

# Add all source files in the graph directory to the project
file(GLOB GRAPH_FILES src/graph/*.cpp)

# Add all source files in the avlTree directory to the project
file(GLOB AVLTREE_FILES src/tree/avlTree/*.cpp)

# Add all source files in the binaryTree directory to the project
file(GLOB BINARYTREE_FILES src/tree/binaryTree/*.cpp)

# Add all source files in the quadTree directory to the project
file(GLOB QUADTREE_FILES src/tree/quadTree/*.cpp)

# Create a library target for the project's source files
add_library(DataStructures SHARED ${INCLUDE_FILES} ${GRAPH_FILES} ${AVLTREE_FILES} ${BINARYTREE_FILES} ${QUADTREE_FILES})

# Set include directories
target_include_directories(DataStructures PUBLIC include)

# Add subdirectories for tests
# add_subdirectory(test)
# add_subdirectory(graph)
# add_subdirectory(tree)
