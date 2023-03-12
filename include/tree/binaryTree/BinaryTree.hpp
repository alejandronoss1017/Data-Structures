#if !defined(DATA_STRUCTURES_BINARY_TREE_HPP)
#define DATA_STRUCTURES_BINARY_TREE_HPP

#include "BinaryNode.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Template class of a Binary Tree.
 *
 * @tparam T Primitive types or classes.

 */
template <typename T>
class BinaryTree
{
    /*  Protected methods that only can be accessed by the class of
    BinaryTree and his derivatives classes  */
protected:
    BinaryNode<T> *root;

private:
    /*  Private methods that only can be accessed by the class of BinaryTree   */

    bool insertNode(const T &data, BinaryNode<T> *node);

    void traversePreOrderHelper(BinaryNode<T> *node);

    void traverseInOrderHelper(BinaryNode<T> *node, ostream &os) const;

    void traversePostOrderHelper(BinaryNode<T> *node);

    void deleteTree(BinaryNode<T> *node);

    bool deleteNodeHelper(const T &data, BinaryNode<T> *node);

    BinaryNode<T> *findSmallestNode(BinaryNode<T> *node);

    BinaryNode<T> *findLargestNode(BinaryNode<T> *node);

    int heightHelper(BinaryNode<T> *node) const;

    bool findNodeHelper(const T &data, BinaryNode<T> *node);

    BinaryNode<T> *copyTree(BinaryNode<T> *node) const;

    bool equals(const BinaryNode<T> *node1, const BinaryNode<T> *node2) const;

    bool emptyHelper(BinaryNode<T> *node);

public:
    BinaryTree();

    explicit BinaryTree(const T &data);

    ~BinaryTree();

    bool insert(const T &data);

    bool remove(const T &data);

    bool find(const T &data);

    void traversePreOrder();

    void traversePostOrder();

    int height();

    T smallest();

    T largest();

    bool empty();

    BinaryTree<T> &operator=(const BinaryTree<T> &otherTree);
    bool operator==(const BinaryTree<T> &otherTree) const;
    bool operator!=(const BinaryTree<T> &otherTree) const;

    bool operator<(const BinaryTree &otherTree) const;

    bool operator>(const BinaryTree &otherTree) const;

    bool operator<=(const BinaryTree &otherTree) const;

    bool operator>=(const BinaryTree &otherTree) const;

    template <typename U>
    friend ostream &operator<<(ostream &os, const BinaryTree<U> &tree);
};

// #include "src/tree/binaryTree/BinaryTree.cpp"

#endif // DATA_STRUCTURES_BINARY_TREE_HPP
