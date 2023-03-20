#if !defined(DATA_STRUCTURES_QUAD_TREE_HPP)
#define DATA_STRUCTURES_QUAD_TREE_HPP

template <typename T>
class QuadTree
{
private:
    T data;

public:
    QuadTree(T data);
    ~QuadTree();
};

#include "../../../src/tree/quadTree/QuadTree.tpp"

#endif // DATA_STRUCTURES_QUAD_TREE_HPP