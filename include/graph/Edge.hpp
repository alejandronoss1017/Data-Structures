
#if !defined(DATA_STRUCTURES_GRAPH_EDGE_HPP)
#define DATA_STRUCTURES_GRAPH_EDGE_HPP

#include <string>

#include "Node.hpp"
#include <ostream>

using namespace std;

template <typename T>
class Edge
{
protected:
    string id;
    double weight;
    Node<T> source;
    Node<T> destination;

public:
    Edge(const string &id, double weight, const Node<T> &source, const Node<T> &destination);

    template <typename U>
    friend ostream &operator<<(ostream &os, const Edge<U> &edge);
};

#include "../../src/graph/Edge.tpp"
#endif // DATA_STRUCTURES_GRAPH_EDGE_HPP
