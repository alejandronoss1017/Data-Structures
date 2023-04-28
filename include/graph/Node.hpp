#if !defined(DATA_STRUCTURES_GRAPH_NODE_HPP)
#define DATA_STRUCTURES_GRAPH_NODE_HPP

#include <string>
#include <ostream>

using namespace std;

/**
 * Node class for Graphs, contains id, matrixId and data.
 *
 * Id is the id of the node in the graph.
 *
 * MatrixId is the id of the node in the adjacency matrix.
 *
 * @tparam T Data is the data of the node.
 *
 *
 */
template <typename T>
class Node
{
private:
    string id;
    int matrixId;
    T data;

public:
    /* Constructors and Destructors */
    Node(T data);
    Node(string id, int matrixId, T data);

    ~Node();

    /* Getters and Setters */
    string getId() const;
    void setId(string id);

    int getMatrixId() const;
    void setMatrixId(int matrixId);

    T getData() const;
    void setData(T data);

    /* Operators */
    bool operator==(const Node &rhs) const;

    bool operator!=(const Node &rhs) const;

    template <typename U>
    friend ostream &operator<<(ostream &os, const Node<U> &node);
};

#include "../../src/graph/Node.tpp"

#endif // DATA_STRUCTURES_GRAPH_NODE_HPP
