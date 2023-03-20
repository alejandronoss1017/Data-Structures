#include "../../../include/tree/quadTree/QuadTree.hpp"

template <typename T>
QuadTree<T>::QuadTree()
{
    this->root = nullptr;
}

template <typename T>
QuadTree<T>::QuadTree(T data)
{
    this->root = new QuadNode<T>(data);
}

template <typename T>
QuadTree<T>::~QuadTree() = default;

template<typename T>
bool QuadTree<T>::insert(T data) {
    return false;
}

