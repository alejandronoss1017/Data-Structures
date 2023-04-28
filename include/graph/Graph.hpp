#ifndef DATA_STRUCTURES_GRAPH_HPP
#define DATA_STRUCTURES_GRAPH_HPP

#include <vector>
#include <string>
#include <map>
#include <ostream>
#include <iostream>
#include <algorithm>

#include "Node.hpp"
#include "Edge.hpp"

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
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the type of the data of the node.
 *
 *
 */
template <typename K, typename T>
class Graph
{
protected:
    map<K, Node<T>> nodes;
    map<string, Edge<T>> edges;
    // vector<vector<int>> edges;

private:
public:
    /* Constructors and Destructors */
    Graph();
    Graph(map<K, Node<T>> nodes, map<string, Edge<T>> edges);
    ~Graph();

    /* Getters and Setters */
    map<K, Node<T>> getNodes() const;
    void setNodes(map<K, Node<T>> nodes);

    map<string, Edge<T>> getEdges() const;
    void setEdges(map<string, Edge<T>> edges);

    /* Operators */

    Graph<K, T> &operator=(const Graph<K, T> &otherGraph);

    bool operator==(const Graph &otherGraph) const;

    bool operator!=(const Graph &otherGraph) const;

    template <typename U, typename R>
    friend ostream &operator<<(ostream &os, const Graph<U, R> &graph);

    /* Methods */
    void addNode(K id, T data);

    void addEdge(K id1, K id2, double weight);

    void addEdge(K id1, K id2, double weight, bool directed);
};

#include "../../src/graph/Graph.tpp"

#endif // DATA_STRUCTURES_GRAPH_HPP