
/**
 * @brief Constructs a new object of the Graph class.
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 */
template <typename K, typename T>
Graph<K, T>::Graph()
{
    Graph::nodes = map<K, Node<K, T>>();
    Graph::edges = map<string, Edge<K, T>>();
}

/**
 * @brief  Constructs a new object of the Graph class, it receives the nodes and edges.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param nodes Map of nodes, where the key is the id of the node and the value is the node.
 * @param edges Map of edges, where the key is the relationship between nodes.
 * @param directed Boolean that indicates if the graph is directed.
 */
template <typename K, typename T>
Graph<K, T>::Graph(map<K, Node<K, T>> nodes, map<string, Edge<K, T>> edges)
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
map<K, Node<K, T>> Graph<K, T>::getNodes() const
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
void Graph<K, T>::setNodes(map<K, Node<K, T>> nodes)
{
    Graph::nodes = nodes;
}

/**
 * @brief Get the Edges object
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @return map<K, Edge<T>> Map of edges, where the key is the relationship between nodes and
 *  the value is the edge.
 */
template <typename K, typename T>
map<string, Edge<K, T>> Graph<K, T>::getEdges() const
{
    return edges;
}

/**
 * @brief Set the Edges object
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param edges where the key is the relationship between nodes and
 *  the value is the edge.
 */
template <typename K, typename T>
void Graph<K, T>::setEdges(map<string, Edge<K, T>> edges)
{
    Graph::edges = edges;
}

/**
 * @brief Equals operator overload, it copies the nodes and edges of a graph to another.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param otherGraph Graph to copy.
 * @return Graph<K, T>& Graph with the nodes and edges copied.
 */
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
 * @param otherGraph Graph to compare.
 * @return true If the graphs are equal, false if aren't.
 */
template <typename K, typename T>
bool Graph<K, T>::operator==(const Graph &otherGraph) const
{
    return nodes == otherGraph.nodes &&
           edges == otherGraph.edges;
}

/**
 * @brief Not equals operator overload, it compares if two graphs are not equal.
 *
 * @tparam K  Key is the type of the key of the node.
 * @tparam T  Data is the data of the node.
 * @param otherGraph  Graph to compare.
 * @return true If the graphs are not equal, false if are.
 * @return false If the graphs are equal, true if aren't.
 */
template <typename K, typename T>
bool Graph<K, T>::operator!=(const Graph &otherGraph) const
{
    return !(otherGraph == *this);
}

/**
 * @brief Output stream operator overload, it prints the nodes and edges of a graph.
 *
 * @tparam U  Key is the type of the key of the node.
 * @tparam R  Data is the data of the node.
 * @param os  Output stream.
 * @param graph  Graph to print.
 * @return ostream& Output stream.
 */
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

/**
 * @brief Add a node to the graph. The id of the node is the key of the map.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param id Id of the node.
 * @param data Data of the node.
 * @return true If the node was added, false if wasn't.
 */
template <typename K, typename T>
bool Graph<K, T>::addNode(K id, T data)
{
    Node<K, T> node = Node<K, T>(id, nodes.size(), data);
    auto success = nodes.insert(pair<K, Node<K, T>>(id, node));

    return success.second;
}

/**
 * @brief Add a node to the graph. The id of the node is the key of the map.
 *
 * @tparam K            Key is the type of the key of the node.
 * @tparam T            Data is the data of the node.
 * @param node          Node to add.
 * @return true         If the node was added.
 * @return false        False if wasn't added.
 */
template <typename K, typename T>
bool Graph<K, T>::addNode(Node<K, T> node)
{

    auto success = nodes.insert(pair<K, Node<K, T>>(node.getId(), node));

    return success.second;
}

/**
 * @brief This method adds an edge between two nodes.
 * The weight the edge is adding in both directions as same as the relation,
 * for example: id1 <-> id2 and id2 <-> id1,
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param id1 The id of the first node.
 * @param id2 The id of the second node.
 * @param weight The weight of the edge.
 * @return true If the edge was added, false if wasn't.
 *
 * @throws bad_alloc If the node doesn't exist.
 */
template <typename K, typename T>
bool Graph<K, T>::addEdge(K id1, K id2, double weight)
{
    Node<K, T> node1;
    Node<K, T> node2;
    try
    {
        node1 = nodes.find(id1)->second;
        node2 = nodes.find(id2)->second;
    }
    catch (const bad_alloc &e)
    {
        std::cerr << "Error: " << e.what() << " Doesn't exist a node with the id1 or id2" << endl;

        return false;
    }

    if (is_same<K, char>::value)
    {
        string node1Id = "";
        string node2Id = "";
        node1Id += node1.getId();
        node2Id += node2.getId();

        auto success = edges.insert(pair<string, Edge<K, T>>((node1Id + "-" + node2Id),
                                                             Edge<K, T>((node1Id + "-" + node2Id), weight, node1, node2)));
        success = edges.insert(pair<string, Edge<K, T>>((node2Id + "-" + node1Id),
                                                        Edge<K, T>((node2Id + "-" + node1Id), weight, node2, node1)));

        return success.second;
    }
    else if (is_arithmetic<K>::value)
    {
        auto success = edges.insert(pair<string, Edge<K, T>>(to_string(id1) + "-" + to_string(id2),
                                                             Edge<K, T>((to_string(id1) + "-" + to_string(id2)), weight, node1, node2)));
        success = edges.insert(pair<string, Edge<K, T>>(to_string(id2) + "-" + to_string(id1),
                                                        Edge<K, T>((to_string(id2) + "-" + to_string(id1)), weight, node2, node1)));

        return success.second;
    }

    auto success = edges.insert(pair<string, Edge<K, T>>(node1.getId() + "-" + node2.getId(), Edge<K, T>((node1.getId() + "-" + node2.getId()), weight, node1, node2)));
    success = edges.insert(pair<string, Edge<K, T>>(node2.getId() + "-" + node1.getId(), Edge<K, T>((node2.getId() + "-" + node1.getId()), weight, node2, node1)));

    return success.second;
}

/**
 * @brief This method adds an edge between two nodes, the edge is
 * added only in one direction as same as the weight.
 *
 * The weight the edge is adding in from id1 node to id2 node,
 * for example: id1 -> id2.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param id1 The id of the first node.
 * @param id2 The id of the second node.
 * @param weight The weight of the edge.
 * @param directed If the relationship is directed or not. If it is false it
 * will only add the edge in one direction. Otherwise it will add the edge in both directions.
 * @return true If the edge was added, false if wasn't.
 *
 * @throws bad_alloc If the node doesn't exist.
 *
 */
template <typename K, typename T>
bool Graph<K, T>::addEdge(K id1, K id2, double weight, bool directed)
{
    Node<K, T> node1;
    Node<K, T> node2;

    try
    {
        node1 = nodes.find(id1)->second;
        node2 = nodes.find(id2)->second;
    }
    catch (const bad_alloc &e)
    {
        std::cerr << "Error: " << e.what() << " Doesn't exist a node with the id1 or id2" << endl;

        return false;
    }

    if (!directed)
    {

        if (is_same<K, char>::value)
        {
            string node1Id = "";
            string node2Id = "";
            node1Id += id1;
            node2Id += id2;

            auto success = edges.insert(pair<string, Edge<K, T>>((node1Id + "-" + node2Id), Edge<K, T>((node1Id + "-" + node2Id), weight, node1, node2)));

            return success.second;
        }
        else if (is_arithmetic<K>::value)
        {
            auto success = edges.insert(pair<string, Edge<K, T>>(to_string(id1 + "-" + id2), Edge<K, T>(to_string(id1 + "-" + id2), weight, node1, node2)));

            return success.second;
        }
    }

    return addEdge(id1, id2, weight);
}

/**
 * @brief This method adds an edge between two nodes, the edge is
 *
 * @tparam K            Key is the type of the key of the node.
 * @tparam T            Data is the data of the node.
 * @param edge          The edge to be added.
 * @return true         If the edge was added.
 * @return false        If the edge wasn't added.
 */
template <typename K, typename T>
bool Graph<K, T>::addEdge(Edge<K, T> edge)
{
    regex pattern("[[:alnum:]]+-[[:alnum:]]+");

    if (regex_match(edge.getId(), pattern))
    {
        auto success = edges.insert(pair<string, Edge<K, T>>(edge.getId(), edge));

        return success.second;
    }

    return false;
}

/**
 * @brief This method removes a node from the graph.
 *
 * @tparam K Key is the type of the key of the node.
 * @tparam T Data is the data of the node.
 * @param id The id of the node to be removed.
 * @return true If the node was removed, false if wasn't.
 * @throws bad_alloc If the node doesn't exist.
 */
template <typename K, typename T>
bool Graph<K, T>::removeNode(K id)
{
    Node<K, T> node;
    string idString = "";

    if (is_same<K, char>::value)
    {
        idString += id;
    }
    else if (is_arithmetic<K>::value)
    {
        idString = to_string(id);
    }
    else if (is_same<K, string>::value)
    {
        idString = id;
    }

    regex patternSource(idString + "-[[:alnum:]]+");
    regex patternDestination("[[:alnum:]]+-" + idString);

    try
    {
        node = nodes.find(id)->second;
    }
    catch (const bad_alloc &e)
    {
        std::cerr << "Error: " << e.what() << " Doesn't exist a node with the id" << endl;

        return false;
    }

    for (auto it = edges.begin(); it != edges.end();)
    {
        if (regex_search(it->first, patternSource) || regex_search(it->first, patternDestination))
        {
            it = edges.erase(it);
        }
        else
        {
            ++it;
        }
    }

    nodes.erase(id);

    return true;
}

/**
 * @brief This method removes a node from the graph.
 *
 * @tparam K            Key is the type of the key of the node.
 * @tparam T            Data is the data of the node.
 * @param id            The id of the node to be removed.
 * @return true         If the node was removed.
 * @return false        If the node wasn't removed.
 * @throws bad_alloc    If the node doesn't exist.
 */
template <typename K, typename T>
bool Graph<K, T>::removeNode(Node<K, T> id)
{
    return removeNode(id.getId());
}
