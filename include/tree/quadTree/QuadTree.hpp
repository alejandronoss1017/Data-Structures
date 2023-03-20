#if !defined(DATA_STRUCTURES_QUAD_TREE_HPP)
#define DATA_STRUCTURES_QUAD_TREE_HPP

#include "QuadNode.hpp"
template <typename T>
class QuadTree
{
protected:
    QuadNode<T> *root;

private:

public:
    QuadTree();

    explicit QuadTree(T data);

    ~QuadTree();

    bool insert(T data);
};

#include "../../../src/tree/quadTree/QuadTree.tpp"

#endif // DATA_STRUCTURES_QUAD_TREE_HPP