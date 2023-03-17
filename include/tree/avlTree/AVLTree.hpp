#if !defined(DATA_STRUCTURES_AVL_TREE_HPP)
#define DATA_STRUCTURES_AVL_TREE_HPP

#include <ostream>
#include "AVLNode.hpp"

using namespace std;

template <typename T>
class AVLTree
{
protected:
    AVLNode<T> *root;

private:
    // TODO: Change order of params -> ALVNode, &data
    AVLNode<T> *insertHelper(const T &data, AVLNode<T> *node);

    int heightHelper(AVLNode<T> *node) const;

    void updateHeight(AVLNode<T> *node);

    int balanceFactor(AVLNode<T> *node) const;

    bool emptyHelper(AVLNode<T> *node) const;

    AVLNode<T> *balance(AVLNode<T> *node);

    AVLNode<T> *rotateRight(AVLNode<T> *node);

    AVLNode<T> *rotateLeft(AVLNode<T> *node);

    bool findNodeHelper(AVLNode<T> *node, const T &data) const;

    void traverseInOrderHelper(AVLNode<T> *node, ostream &os) const;

    // TODO: preorder and postorder methods

    // TODO: comment methods, change spanish to english comments
public:
    AVLTree();

    explicit AVLTree(const T &data);

    virtual ~AVLTree();

    bool insert(const T &data);

    // TODO: Implement remove method
    bool remove(const T &data);

    bool find(const T &data) const;

    bool empty() const;

    // TODO: smallest,largest and overloads
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
