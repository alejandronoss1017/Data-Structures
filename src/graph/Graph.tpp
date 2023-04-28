
/**
 * @brief Constructs a new object of the Graph class.
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 */
template <typename K, typename T>
Graph<K, T>::Graph()
{
    Graph::nodes = map<K, Node<T>>();
    Graph::edges = map<string, Edge<T>>();
}

/**
 * @brief  Constructs a new object of the Graph class, it receives the nodes, edges and if the graph is directed.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param nodes Map of nodes, where the key is the id of the node and the value is the node.
 * @param edges Matrix of edges, where the first index is the id of the node and the second index is the id of the node that is connected to the first node. The value of the matrix is the weight of the edge.
 * @param directed Boolean that indicates if the graph is directed.
 */
template <typename K, typename T>
Graph<K, T>::Graph(map<K, Node<T>> nodes, map<string, Edge<T>> edges)
{
    Graph::nodes = nodes;
    Graph::edges = edges;
}

/**
 * @brief Destroy the Graph object
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 */
template <typename K, typename T>
Graph<K, T>::~Graph() = default;

/**
 * @brief Get the Nodes object
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @return map<K, Node<T>> Map of nodes, where the key is the id of the node and the value is the node.
 */
template <typename K, typename T>
map<K, Node<T>> Graph<K, T>::getNodes() const
{
    return nodes;
}

/**
 * @brief Set the Nodes object
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param nodes Map of nodes, where the key is the id of the node and the value is the node.
 */
template <typename K, typename T>
void Graph<K, T>::setNodes(map<K, Node<T>> nodes)
{
    Graph::nodes = nodes;
}

/**
 * @brief Get the Edges object
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @return map<K, Edge<T>> Matrix of edges, where the first index is the id of the node and the second index is the id of the node that is connected to the first node. The value of the matrix is the weight of the edge.
 */
template <typename K, typename T>
map<string, Edge<T>> Graph<K, T>::getEdges() const
{
    return edges;
}

/**
 * @brief Set the Edges object
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param edges Matrix of edges, where the first index is the id of the node and the second index is the id of the node that is connected to the first node. The value of the matrix is the weight of the edge.
 */
template <typename K, typename T>
void Graph<K, T>::setEdges(map<string, Edge<T>> edges)
{
    Graph::edges = edges;
}

template <typename K, typename T>
Graph<K, T> &Graph<K, T>::operator=(const Graph<K, T> &otherGraph)
{
    if (this == &otherGraph)
    {
        return *this;
    }

    nodes = otherGraph.nodes;

    edges = otherGraph.edges;

    return *this;
}

/**
 * @brief Equals operator overload, it compares if two graphs are equal.
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param rhs Graph to compare.
 * @return true If the graphs are equal, false if aren't.
 */
template <typename K, typename T>
bool Graph<K, T>::operator==(const Graph &otherGraph) const
{
    return nodes == otherGraph.nodes &&
           edges == otherGraph.edges;
}

template <typename K, typename T>
bool Graph<K, T>::operator!=(const Graph &otherGraph) const
{
    return !(otherGraph == *this);
}

template <typename U, typename R>
ostream &operator<<(ostream &os, const Graph<U, R> &graph)
{
    os << "nodes: " << endl;
    for (auto &node : graph.nodes)
    {
        os << node.first << ": " << node.second << endl;
    }

    os << "edges: " << endl;
    for (auto &edge : graph.edges)
    {
        os << edge.first << ": " << edge.second << endl;
    }

    return os;
}

template <typename K, typename T>
void Graph<K, T>::addNode(K id, T data)
{
    /*
        constexpr is used to define a compile-time constant expression that is
        evaluated at compile time to determine if the type of K is equal to string.

        The expression is_same_v<K, string> uses the type trait is_same to check if
        the type of K is the same as the type string. It returns a bool value indicating
        whether the types are the same or not.
    */
    if constexpr (is_same_v<K, string>)
    {
        Node<T> node = Node(id, nodes.size(), data);
        nodes.insert(pair<K, Node<T>>(id, node));
    }
    else
    {

        Node<T> node = Node(to_string(id), nodes.size(), data);
        nodes.insert(pair<K, Node<T>>(id, node));
    }
}

/**
 * @brief This method adds an edge between two nodes. If the graph is directed,
 * the edge is added in both directions. By default, the weight the edge is adding
 * in both directions as same as the relation, for example: id1 <-> id2 and id2 <-> id1,
 * the weight is the same for both edges.
 *
 *
 * @tparam T Data is the data of the node.
 * @param id1 The id of the first node.
 * @param id2 The id of the second node.
 * @param weight The weight of the edge.
 */
template <typename K, typename T>
void Graph<K, T>::addEdge(K id1, K id2, double weight)
{

    Node<T> node1 = nodes.find(id1)->second;
    Node<T> node2 = nodes.find(id2)->second;

    string edgeId = node1.getId() + "-" + node2.getId();

    edges.insert(pair<string, Edge<T>>(edgeId, Edge<T>(edgeId, weight, node1, node2)));
    edges.insert(pair<string, Edge<T>>((node2.getId() + "-" + node1.getId()), Edge<T>(edgeId, weight, node2, node1)));
}

/**
 * @brief This method adds an edge between two nodes. If the graph is directed, the edge is added in both directions.
 * The weight the edge is adding in both directions as same as the relation, for example: id1 <-> id2 and id2 <-> id1,
 * the weight is the same for both edges.
 *
 * If directed is set to false, the edge is added only in one direction as same as the weight.
 *
 * for example: id1 -> id2, the weight is only for this edge.
 *
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param id1 The id of the first node.
 * @param id2 The id of the second node.
 * @param weight The weight of the edge.
 * @param directed If the graph is directed or not.
 */
template <typename K, typename T>
void Graph<K, T>::addEdge(K id1, K id2, double weight, bool directed)
{
    if (!directed)
    {
        Node<T> node1 = nodes.find(id1)->second;
        Node<T> node2 = nodes.find(id2)->second;

        string edgeId = node1.getId() + "-" + node2.getId();

        edges.insert(pair<string, Edge<T>>(edgeId, Edge<T>(edgeId, weight, node1, node2)));
    }
    else
    {
        addEdge(id1, id2, weight);
    }
}