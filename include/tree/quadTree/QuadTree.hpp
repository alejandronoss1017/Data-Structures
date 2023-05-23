#if !defined(DATA_STRUCTURES_QUAD_TREE_HPP)
#define DATA_STRUCTURES_QUAD_TREE_HPP

#include "QuadNode.hpp"
#include <ostream>
class QuadTree
{
protected:
    QuadNode *root;

    int maxDepth;
    int maxPoints;
    int nodeCount;
    int pointCount;

private:
    QuadNode *insertHelper(QuadNode *node, const double &coordinateX, const double &coordinateY);
    QuadNode *removeHelper(QuadNode *node, const double &coordinateX, const double &coordinateY);
    QuadNode *findMinHelper(QuadNode *node);
    QuadNode *findMaxHelper(QuadNode *node);
    QuadNode *findHelper(QuadNode *node, const double &coordinateX, const double &coordinateY);
    QuadNode *clearHelper(QuadNode *node);
    void traverseInOrderHelper(QuadNode *node, ostream &os) const;
    void traversePreOrderHelper();
    void traversePostOrderHelper();
    bool equals(const QuadNode *node1, const QuadNode *node2);

public:
    QuadTree();
    QuadTree(const double &coordinateX, const double &coordinateY);
    ~QuadTree();

    bool insert(const double &coordinateX, const double &coordinateY);
    bool remove(const double &coordinateX, const double &coordinateY);
    bool find(const double &coordinateX, const double &coordinateY);
    bool empty();
    void clear();
    int height();
    int size();
    void traverseInOrder();
    void traversePreOrder();
    void traversePostOrder();

    friend ostream &operator<<(ostream &os, const QuadTree &tree);
};

// This must removed when compiling in CMake
// #include "../../../src/tree/quadTree/QuadTree.cpp"

#endif // DATA_STRUCTURES_QUAD_TREE_HPP