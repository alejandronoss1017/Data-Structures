
/**
 * @brief Constructs a new object of the Graph class, by default
 * the graph is directed.
 *
 * @tparam T Data is the data of the node.
 */
template <typename T>
Graph<T>::Graph()
{
    Graph::nodes = map<string, Node<T>>();
    Graph::edges = vector<vector<int>>();
    Graph::directed = true;
}

/**
 * @brief Construct a new object of the Graph class, it receives if the graph is directed.
 *
 * @tparam T Data is the data of the node.
 * @param directed Boolean that indicates if the graph is directed.
 */
template <typename T>
Graph<T>::Graph(bool directed)
{
    Graph::nodes = map<string, Node<T>>();
    Graph::edges = vector<vector<int>>();
    Graph::directed = directed;
}

/**
 * @brief  Constructs a new object of the Graph class, it receives the nodes, edges and if the graph is directed.
 *
 * @tparam T Data is the data of the node.
 * @param nodes Map of nodes, where the key is the id of the node and the value is the node.
 * @param edges Matrix of edges, where the first index is the id of the node and the second index is the id of the node that is connected to the first node. The value of the matrix is the weight of the edge.
 * @param directed Boolean that indicates if the graph is directed.
 */
template <typename T>
Graph<T>::Graph(map<string, Node<T>> nodes, vector<vector<int>> edges, bool directed)
{
    Graph::nodes = nodes;
    Graph::edges = edges;
    Graph::directed = directed;
}

template <typename T>
Graph<T>::~Graph() = default;

template <typename T>
map<string, Node<T>> Graph<T>::getNodes() const
{
    return nodes;
}

template <typename T>
void Graph<T>::setNodes(map<string, Node<T>> nodes)
{
    Graph::nodes = nodes;
}

template <typename T>
vector<vector<int>> Graph<T>::getEdges() const
{
    return edges;
}

template <typename T>
void Graph<T>::setEdges(vector<vector<int>> edges)
{
    Graph::edges = edges;
}

template <typename T>
bool Graph<T>::isDirected() const
{
    return directed;
}

template <typename T>
bool Graph<T>::operator==(const Graph &rhs) const
{
    return nodes == rhs.nodes &&
           edges == rhs.edges;
}

template <typename T>
bool Graph<T>::operator!=(const Graph &rhs) const
{
    return !(rhs == *this);
}

template <typename U>
ostream &operator<<(ostream &os, const Graph<U> &graph)
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

template <typename T>
void Graph<T>::addRowAndColumn()
{
    for (auto &edge : edges)
    {
        edge.push_back(0);
    }

    vector<int> newRow = vector<int>(edges.size() + 1, 0);
    edges.push_back(newRow);
}

template <typename T>
void Graph<T>::addNode(string id, T data)
{
    Node node = Node(id, nodes.size(), data);

    nodes.insert(pair<string, Node<T>>(id, node));
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
template <typename T>
void Graph<T>::addEdge(string id1, string id2, int weight)
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