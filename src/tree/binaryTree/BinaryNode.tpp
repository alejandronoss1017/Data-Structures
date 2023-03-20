#include "../../../include/tree/binaryTree/BinaryNode.hpp"

/**
 * @brief Construct a new Binary Node.
 *
 * @tparam T Primitive types or classes.
 * @param data Value of the Binary Node.
 */
template <typename T>
BinaryNode<T>::BinaryNode(const T &data)
{
    this->data = data;
    this->rightChild = nullptr;
    this->leftChild = nullptr;
}

/**
 * @brief Destroys a Binary Node.
 *
 * @tparam T Primitive types or classes.
 */
template <typename T>
BinaryNode<T>::~BinaryNode() = default;

/**
 * @brief Gets the value of a Binary Node.
 *
 * @tparam T Primitive types or classes.
 * @return T Value of the Binary Node.
 */
template <typename T>
T BinaryNode<T>::getData() const
{
    return this->data;
}

/**
 * @brief Sets the value of a Binary Node.
 *
 * @tparam T Primitive types or classes.
 * @param value Value to be inserted into the Binary Node.
 */
template <typename T>
void BinaryNode<T>::setData(const T &value)
{
    this->data = value;
}

/**
 * @brief Gets the pointer to the left child of a Binary Node.
 *
 * @tparam T Primitive types or classes.
 * @return BinaryNode<T>*
 */
template <typename T>
BinaryNode<T> *BinaryNode<T>::getLeftChild() const
{
    return this->leftChild;
}

/**
 * @brief Sets a node to the left child of a Binary Node.
 *
 * @tparam T Primitive types or classes.
 * @param node Binary Node to be inserted.
 */
template <typename T>
void BinaryNode<T>::setLeftChild(BinaryNode<T> *node)
{
    this->leftChild = node;
}

/**
 * @brief Gets the right child of a Binary Node.
 *
 * @tparam T Primitive types or classes.
 * @return BinaryNode<T>*
 */
template <typename T>
BinaryNode<T> *BinaryNode<T>::getRightChild() const
{
    return this->rightChild;
}

/**
 * @brief Sets a node to the right child of a Binary Node.
 *
 * @tparam T Primitive types or classes.
 * @param node Binary Node to be inserted.
 */
template <typename T>
void BinaryNode<T>::setRightChild(BinaryNode<T> *node)
{
    this->rightChild = node;
}
