#if !defined(DATA_STRUCTURES_AVL_TREE_HPP)
#define DATA_STRUCTURES_AVL_TREE_HPP

#include <ostream>
#include "AVLNode.hpp"

template <typename T>
class AVLTree
{
protected:
    AVLNode<T> *root;

private:
    bool insertNode(const T &data, AVLNode<T> *node);

    int heightHelper(AVLNode<T> *node) const;

    AVLNode<T> *rightRotation(AVLNode<T> *node);

    AVLNode<T> *leftRotation(AVLNode<T> *node);

    AVLNode<T> *rightLeftRotation(AVLNode<T> *node);

    AVLNode<T> *leftRightRotation(AVLNode<T> *node);

    // void traversePreOrderHelper(AVLNode<T> *node);

    void traverseInOrderHelper(AVLNode<T> *node, ostream &os) const;

    // void traversePostOrderHelper(AVLNode<T> *node);

    // void deleteTree(AVLNode<T> *node);

    // bool deleteNodeHelper(const T &data, AVLNode<T> *node);

    // AVLNode<T> *findSmallestNode(AVLNode<T> *node);

    // AVLNode<T> *findLargestNode(AVLNode<T> *node);

    // bool findNodeHelper(const T &data, AVLNode<T> *node);

    // AVLNode<T> *copyTree(AVLNode<T> *node) const;

    // bool equals(const AVLNode<T> *node1, const AVLNode<T> *node2) const;

    // bool emptyHelper(AVLNode<T> *node);

public:
    AVLTree();

    explicit AVLTree(const T &data);

    virtual ~AVLTree();

    bool insert(const T &data);

    bool remove(const T &data);

    int height();

    template <typename U>
    friend ostream &operator<<(ostream &os, const AVLTree<U> &tree);
};

#include "../../../src/tree/avlTree/AVLTree.cpp"

#endif // DATA_STRUCTURES_AVL_TREE_HPP
