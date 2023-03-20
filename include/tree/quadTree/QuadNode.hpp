#if !defined(DATA_STRUCTURES_QUAD_NODE_HPP)
#define DATA_STRUCTURES_QUAD_NODE_HPP

#include <array>

using namespace std;

template <typename T>
class QuadNode
{
protected:
    T data;
    array<QuadNode *, 4> children;

public:
    QuadNode(T data);

    QuadNode(T data, array<QuadNode *, 4> children);

    ~QuadNode();

    T getData() const;

    void setData(T data);

    const array<QuadNode *, 4> &getChildren() const;

    void setChildren(const array<QuadNode *, 4> &children);

};

#include "../../../src/tree/quadTree/QuadNode.tpp"

#endif // DATA_STRUCTURES_QUAD_NODE_HPP
