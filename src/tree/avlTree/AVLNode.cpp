#include "../../../include/tree/avlTree/AVLNode.hpp"

template <typename T>
AVLNode<T>::AVLNode(const T &data)
{
    this->data = data;
    this->height = 1;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}
template <typename T>
AVLNode<T>::AVLNode(const T &data, int height, AVLNode<T> *leftChild, AVLNode<T> *rightChild)
{
    this->data = data;
    this->height = height;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
}

template <typename T>
void AVLNode<T>::setData(T data)
{
    AVLNode::data = data;
}

template <typename T>
T AVLNode<T>::getData() const
{
    return data;
}

template <typename T>
int AVLNode<T>::getHeight() const
{
    return height;
}
template <typename T>
void AVLNode<T>::setHeight(int height)
{
    AVLNode::height = height;
}

template <typename T>
AVLNode<T> *AVLNode<T>::getLeftChild() const
{
    return leftChild;
}

template <typename T>
void AVLNode<T>::setLeftChild(AVLNode<T> *leftChild)
{
    AVLNode::leftChild = leftChild;
}

template <typename T>
AVLNode<T> *AVLNode<T>::getRightChild() const
{
    return rightChild;
}

template <typename T>
void AVLNode<T>::setRightChild(AVLNode<T> *rightChild)
{
    AVLNode::rightChild = rightChild;
}
