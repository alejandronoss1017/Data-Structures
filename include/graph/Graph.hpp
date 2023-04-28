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

template <typename K, typename T>
class Graph
{
protected:
    bool directed;
    map<K, Node<T>> nodes;
    vector<vector<int>> edges;

private:
    void addRowAndColumn();

public:
    /* Constructors and Destructors */
    Graph();
    Graph(bool directed);
    Graph(map<K, Node<T>> nodes, vector<vector<int>> edges, bool directed);
    ~Graph();

    /* Getters and Setters */
    map<K, Node<T>> getNodes() const;
    void setNodes(map<K, Node<T>> nodes);

    vector<vector<int>> getEdges() const;
    void setEdges(vector<vector<int>> edges);

    bool isDirected() const;

    /* Operators */

    Graph<K, T> &operator=(const Graph<K, T> &other);

    bool operator==(const Graph &rhs) const;

    bool operator!=(const Graph &rhs) const;

    template <typename U, typename R>
    friend ostream &operator<<(ostream &os, const Graph<U, R> &graph);

    /* Methods */
    void addNode(K id, T data);

    void addEdge(K id1, K id2, int weight);
};

#include "../../src/graph/Graph.tpp"

#endif // DATA_STRUCTURES_GRAPH_HPP