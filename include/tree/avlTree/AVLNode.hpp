#if !defined(DATA_STRUCTURES_AVL_NODE_H)
#define DATA_STRUCTURES_AVL_NODE_H

#include "../binaryTree/BinaryNode.hpp"

template <typename T>
class AVLNode
{
protected:
    T data;
    int height;
    AVLNode<T> *leftChild;
    AVLNode<T> *rightChild;

public:
    /*  Constructors  */
    explicit AVLNode(const T &data);

    /*  Getters and Setters  */
    T getData() const;

    int getHeight() const;

    void setHeight(int height);

    void setData(T data);

    void setLeftChild(AVLNode<T> *leftChild);

    AVLNode<T> *getLeftChild() const;

    void setRightChild(AVLNode<T> *rightChild);

    AVLNode<T> *getRightChild() const;
};

#include "../../../src/tree/avlTree/AVLNode.cpp"
#endif // DATA_STRUCTURES_AVL_NODE_H
