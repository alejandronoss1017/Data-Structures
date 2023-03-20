#ifndef DATA_STRUCTURES_GRAPH_HPP
#define DATA_STRUCTURES_GRAPH_HPP

template <typename T>
class Graph
{
private:
    T data;

public:
    Graph(T data);
    ~Graph();
};

#include "../../src/graph/Graph.tpp"

#endif // DATA_STRUCTURES_GRAPH_HPP