
#if !defined(DATA_STRUCTURES_GRAPH_EDGE_HPP)
#define DATA_STRUCTURES_GRAPH_EDGE_HPP

#include <string>

#include "Node.hpp"
#include <ostream>

using namespace std;

/**
 * @brief Edge class, contains the source and destination nodes.
 *
 * @tparam K  Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T  Data is the type of the data of the node.
 */
template <typename K, typename T>
class Edge
{
protected:
    /* Attributes */

    // id of the edge, composed by the id of the first node and the id of the second node.
    string id;

    // weight of the edge.
    double weight;

    // source node of the edge.
    Node<K, T> source;

    // destination node of the edge.
    Node<K, T> destination;

public:
    /* Constructors and Destructors */

    Edge();
    Edge(const string &id, double weight, const Node<K, T> &source, const Node<K, T> &destination);
    ~Edge();

    /* Getters and Setters */

    const string &getId() const;
    void setId(const string &id);

    double getWeight() const;
    void setWeight(double weight);

    const Node<K, T> &getSource() const;
    void setSource(const Node<K, T> &source);

    const Node<K, T> &getDestination() const;
    void setDestination(const Node<K, T> &destination);

    /* Operators */

    template <typename U, typename L>
    friend ostream &operator<<(ostream &os, const Edge<U, L> &edge);

    /* Methods */
};

#include "../../src/graph/Edge.tpp"
#endif // DATA_STRUCTURES_GRAPH_EDGE_HPP
