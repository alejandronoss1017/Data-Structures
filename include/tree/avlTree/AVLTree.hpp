#if !defined(DATA_STRUCTURES_AVL_TREE_HPP)
#define DATA_STRUCTURES_AVL_TREE_HPP

#include <iostream>
#include "AVLNode.hpp"

using namespace std;

/**
 * @brief Template class of a AVL Tree.
 *
 * @tparam T Primitive types or classes.
 */
template <typename T>
class AVLTree
{
protected:
    AVLNode<T> *root;

private:
    AVLNode<T> *insertHelper(AVLNode<T> *node, const T &data);

    AVLNode<T> *removeHelper(AVLNode<T> *node, const T &data);

    AVLNode<T> *findSmallestNode(AVLNode<T> *node);

    AVLNode<T> *findLargestNode(AVLNode<T> *node);

    int heightHelper(AVLNode<T> *node) const;

    void updateHeight(AVLNode<T> *node);

    int balanceFactor(AVLNode<T> *node) const;

    bool emptyHelper(AVLNode<T> *node) const;

    void clearHelper(AVLNode<T> *node);

    bool equals(const AVLNode<T> *node1, const AVLNode<T> *node2) const;

    AVLNode<T> *balance(AVLNode<T> *node);

    AVLNode<T> *rotateRight(AVLNode<T> *node);

    AVLNode<T> *rotateLeft(AVLNode<T> *node);

    AVLNode<T> *copyTree(AVLNode<T> *node) const;

    bool findNodeHelper(AVLNode<T> *node, const T &data) const;

    void traverseInOrderHelper(AVLNode<T> *node, ostream &os) const;

    void traversePreOrderHelper(AVLNode<T> *node) const;

    void traversePostOrderHelper(AVLNode<T> *node) const;

    // TODO: comment methods, change spanish to english comments
public:
    AVLTree();

    explicit AVLTree(const T &data);

    virtual ~AVLTree();

    bool insert(const T &data);

    bool remove(const T &data);

    void clear();

    bool find(const T &data) const;

    void traversePreOrder();

    void traversePostOrder();

    bool empty() const;

    T smallest() const;

    T largest() const;

    int height() const;

    AVLTree<T> &operator=(const AVLTree<T> &otherTree);

    bool operator==(const AVLTree<T> &otherTree) const;

    bool operator!=(const AVLTree<T> &otherTree) const;

    bool operator<(const AVLTree &otherTree) const;

    bool operator>(const AVLTree &otherTree) const;

    bool operator<=(const AVLTree &otherTree) const;

    bool operator>=(const AVLTree &otherTree) const;

    template <typename U>
    friend ostream &operator<<(ostream &os, const AVLTree<U> &tree);
};

// This must removed when compiling in CMake
#include "../../../src/tree/avlTree/AVLTree.cpp"

#endif // DATA_STRUCTURES_AVL_TREE_HPP
