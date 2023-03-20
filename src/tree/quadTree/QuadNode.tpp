
#include "../../../include/tree/quadTree/QuadNode.hpp"

template <typename T>
QuadNode<T>::QuadNode(T data)
{
    this->data = data;
    this->children.fill(nullptr);
}

template <typename T>
QuadNode<T>::QuadNode(T data, array<QuadNode *, 4> children)
{
    this->data = data;
    this->children = children;
}

template <typename T>
QuadNode<T>::~QuadNode() = default;

template <typename T>
T QuadNode<T>::getData() const
{
    return data;
}

template <typename T>
void QuadNode<T>::setData(T data)
{
    QuadNode::data = data;
}

template <typename T>
const array<QuadNode<T> *, 4> &QuadNode<T>::getChildren() const
{
    return children;
}

template <typename T>
void QuadNode<T>::setChildren(const array<QuadNode *, 4> &children)
{
    QuadNode::children = children;
}