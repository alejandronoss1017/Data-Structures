#ifndef DATA_STRUCTURES_GRAPH_HPP
#define DATA_STRUCTURES_GRAPH_HPP

#include <vector>
#include <string>
#include <map>
#include <ostream>
#include <iostream>
#include <algorithm>

#include "Node.hpp"

using namespace std;

/**
 * Graph class, contains nodes and edges.
 *
 * Nodes is a map of nodes, where the key is the id of the node and the
 * value is the node.
 *
 * Edges is a matrix of edges, where the first index is the id
 * of the node and the second index is the id of the node that
 * is connected to the first node. The value of the matrix is
 * the weight of the edge.
 *
 *
 * @tparam T Data is the data of the node.
 *
 *
 */

template <typename T>
class Graph
{
protected:
    bool directed;
    map<string, Node<T>> nodes;
    vector<vector<int>> edges;

private:
    void addRowAndColumn();

public:
    /* Constructors and Destructors */
    Graph();
    Graph(bool directed);
    Graph(map<string, Node<T>> nodes, vector<vector<int>> edges, bool directed);
    ~Graph();

    /* Getters and Setters */
    map<string, Node<T>> getNodes() const;
    void setNodes(map<string, Node<T>> nodes);

    vector<vector<int>> getEdges() const;
    void setEdges(vector<vector<int>> edges);

    bool isDirected() const;

    /* Operators */
    bool operator==(const Graph &rhs) const;

    bool operator!=(const Graph &rhs) const;

    template <typename U>
    friend ostream &operator<<(ostream &os, const Graph<U> &graph);

    /* Methods */
    void addNode(string id, T data);

    void addEdge(string id1, string id2, int weight);
};

#include "../../src/graph/Graph.tpp"

#endif // DATA_STRUCTURES_GRAPH_HPP