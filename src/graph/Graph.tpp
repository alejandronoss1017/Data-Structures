
/**
 * @brief Constructs a new object of the Graph class, by default
 * the graph is directed.
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 */
template <typename K, typename T>
Graph<K, T>::Graph()
{
    Graph::nodes = map<K, Node<T>>();
    Graph::edges = vector<vector<int>>();
    Graph::directed = true;
}

/**
 * @brief Construct a new object of the Graph class, it receives if the graph is directed.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param directed Boolean that indicates if the graph is directed.
 */
template <typename K, typename T>
Graph<K, T>::Graph(bool directed)
{
    Graph::nodes = map<K, Node<T>>();
    Graph::edges = vector<vector<int>>();
    Graph::directed = directed;
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
Graph<K, T>::Graph(map<K, Node<T>> nodes, vector<vector<int>> edges, bool directed)
{
    Graph::nodes = nodes;
    Graph::edges = edges;
    Graph::directed = directed;
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
 * @return vector<vector<int>> Matrix of edges, where the first index is the id of the node and the second index is the id of the node that is connected to the first node. The value of the matrix is the weight of the edge.
 */
template <typename K, typename T>
vector<vector<int>> Graph<K, T>::getEdges() const
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
void Graph<K, T>::setEdges(vector<vector<int>> edges)
{
    Graph::edges = edges;
}

/**
 * @brief Get the boolean that indicates if the graph is directed.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @return true If the graph is directed, false if isn't.
 */
template <typename K, typename T>
bool Graph<K, T>::isDirected() const
{
    return directed;
}

template <typename K, typename T>
Graph<K, T> &Graph<K, T>::operator=(const Graph<K, T> &other)
{
    if (this == &other)
    {
        return *this;
    }

    directed = other.directed;

    nodes = other.nodes;

    edges = other.edges;

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
bool Graph<K, T>::operator==(const Graph &rhs) const
{
    return nodes == rhs.nodes &&
           edges == rhs.edges;
}

template <typename K, typename T>
bool Graph<K, T>::operator!=(const Graph &rhs) const
{
    return !(rhs == *this);
}

template <typename U, typename R>
ostream &operator<<(ostream &os, const Graph<U, R> &graph)
{

    os << "directed: " << (graph.directed ? "True" : "False") << endl;

    os << "nodes: " << endl;
    for (auto &node : graph.nodes)
    {
        os << node.first << ": " << node.second << endl;
    }

    os << "edges: " << endl;
    for (auto &edge : graph.edges)
    {
        for (auto &node : edge)
        {
            os << node << " ";
        }
        os << endl;
    }

    return os;
}

template <typename K, typename T>
void Graph<K, T>::addRowAndColumn()
{
    for (auto &edge : edges)
    {
        edge.push_back(0);
    }

    vector<int> newRow = vector<int>(edges.size() + 1, 0);
    edges.push_back(newRow);
}

template <typename K, typename T>
void Graph<K, T>::addNode(K id, T data)
{
    Node node = Node(id, nodes.size(), data);

    nodes.insert(pair<K, Node<T>>(id, node));
    addRowAndColumn();
}

/**
 * @brief This method adds an edge between two nodes. If the graph is directed,
 * the edge is added in both directions. If the graph is not directed,
 * the edge is only added in one direction, from id1 to id2.
 *
 *
 * @tparam T Data is the data of the node.
 * @param id1 The id of the first node.
 * @param id2 The id of the second node.
 * @param weight The weight of the edge.
 */
template <typename K, typename T>
void Graph<K, T>::addEdge(K id1, K id2, int weight)
{
    if (directed)
    {
        int index1 = nodes.find(id1)->second.getMatrixId();
        int index2 = nodes.find(id2)->second.getMatrixId();
        edges[index1][index2] = weight;
        edges[index2][index1] = weight;
    }
    else
    {
        int index1 = nodes.find(id1)->second.getMatrixId();
        int index2 = nodes.find(id2)->second.getMatrixId();

        edges[index1][index2] = weight;
    }
}