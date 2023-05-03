
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
 * @return true If one of the edges were added
 * @return false If none of the edges were added.
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

    ostringstream oss;

    oss << id1 << "-" << id2;

    string edgeId = oss.str();

    auto success1 = edges.insert(pair<string, Edge<K, T>>(edgeId, Edge<K, T>(edgeId, weight, node1, node2)));

    oss.str("");

    oss << id2 << "-" << id1;

    edgeId = oss.str();

    auto success2 = edges.insert(pair<string, Edge<K, T>>(edgeId, Edge<K, T>(edgeId, weight, node2, node1)));

    return (success1.second || success2.second);
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
 * @return true If one or both edges were added.
 * @return false If both nodes weren't added.
 *
 * @throws bad_alloc If the node doesn't exist.
 *
 */
template <typename K, typename T>
bool Graph<K, T>::addEdge(K id1, K id2, double weight, bool directed)
{
    Node<K, T> node1;
    Node<K, T> node2;

    if (directed)
    {

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

        ostringstream oss;

        oss << id1 << "-" << id2;

        string edgeId = oss.str();

        auto success1 = edges.insert(pair<string, Edge<K, T>>(edgeId, Edge<K, T>(edgeId, weight, node1, node2)));

        return success1.second;
    }
    return addEdge(id1, id2, weight);
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

    ostringstream oss;

    oss << id;

    string idString = oss.str();

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

/**
 * @brief This method removes an edge from the graph, in both directions.
 *
 * @tparam K                Key is the type of the key of the node.
 * @tparam T                Data is the data of the node.
 * @param id1               The id of the first node.
 * @param id2               The id of the second node.
 * @return true             If the edge was removed.
 * @return false            If the edge wasn't removed.
 * @throws runtime_error    If the edge doesn't exist.
 */
template <typename K, typename T>
bool Graph<K, T>::removeEdge(string id1, string id2)
{
    try
    {
        auto success1 = edges.erase(id1 + "-" + id2);
        auto success2 = edges.erase(id2 + "-" + id1);

        if (!success1)
        {
            throw runtime_error("Error: Edge " + id1 + "-" + id2 + " not exist");
        }
        if (!success2)
        {
            cout << "Warning: Edge " + id2 + "-" + id1 + " not exist" << endl;
        }
    }
    catch (const runtime_error &e)
    {
        std::cerr << e.what() << endl;

        return false;
    }
    return true;
}

/**
 * @brief This method removes an edge from the graph, in one or both directions.
 *        If the edge is directed, it will be removed just in one direction,
 *        otherwise it will be removed in both directions.
 *
 * @tparam K                    Key is the type of the key of the node.
 * @tparam T                    Data is the data of the node.
 * @param id1                   The id of the first node.
 * @param id2                   The id of the second node.
 * @param directed              If the edge is directed or not.
 * @return true                 If the edge was removed.
 * @return false                If the edge wasn't removed.
 * @throws runtime_error        If the edge doesn't exist.
 */
template <typename K, typename T>
bool Graph<K, T>::removeEdge(string id1, string id2, bool directed)
{
    if (directed)
    {
        try
        {
            auto success = edges.erase(id1 + "-" + id2);

            if (!success)
            {
                throw runtime_error("Error: Edge " + id1 + "-" + id2 + " not exist");
            }
        }
        catch (const runtime_error &e)
        {
            std::cerr << e.what() << endl;

            return false;
        }
        return true;
    }

    return removeEdge(id1, id2);
}

/**
 * @brief This method removes an edge from the graph, the edge is removed in both directions.
 *
 * @tparam K                Key is the type of the key of the node.
 * @tparam T                Data is the data of the node.
 * @param edge              The edge to be removed.
 * @return true             If the edge was removed.
 * @return false            If the edge wasn't removed.
 * @throws runtime_error    If the edge doesn't exist.
 */
template <typename K, typename T>
bool Graph<K, T>::removeEdge(Edge<K, T> edge)
{
    try
    {

        ostringstream oss1;
        oss1 << edge.getSource().getId();

        ostringstream oss2;
        oss2 << edge.getDestination().getId();

        string id1 = oss1.str();

        string id2 = oss2.str();

        auto success1 = edges.erase(id1 + "-" + id2);
        auto success2 = edges.erase(id2 + "-" + id1);

        if (!success1)
        {
            throw runtime_error("Error: Edge " + edge.getId() + " not exist");
        }

        if (!success2)
        {
            cout << "Warning: Edge " + id2 + " not exist" << endl;
        }
    }
    catch (const runtime_error &e)
    {
        std::cerr << e.what() << endl;

        return false;
    }
    return true;
}

/**
 * @brief This method removes an edge from the graph, in one or both directions.
 *        If the edge is directed, it will be removed just in one direction,
 *        otherwise it will be removed in both directions.
 *
 * @tparam K                Key is the type of the key of the node.
 * @tparam T                Data is the data of the node.
 * @param edge              The edge to be removed.
 * @param directed          If the edge is directed or not.
 * @return true             If the edge was removed.
 * @return false            If the edge wasn't removed.
 * @throws runtime_error    If the edge doesn't exist.
 */
template <typename K, typename T>
bool Graph<K, T>::removeEdge(Edge<K, T> edge, bool directed)
{

    if (directed)
    {
        try
        {
            string idToRemove1 = edge.getId();

            auto success = edges.erase(idToRemove1);

            if (!success)
            {
                throw runtime_error("Error: Edge " + edge.getId() + " not exist");
            }
        }
        catch (const runtime_error &e)
        {
            std::cerr << e.what() << endl;

            return false;
        }
        return true;
    }

    return removeEdge(edge);
}

/**
 * @brief Finds all the neighbors of a node.
 *
 *
 * @tparam K                Key is the type of the key of the node.
 * @tparam T                Data is the data of the node.
 * @param id                The id of the node.
 * @return                  A vector with all the neighbors of the node.
 */
template <typename K, typename T>
vector<Node<K, T>> Graph<K, T>::getNeighbors(K id)
{
    vector<Node<K, T>> neighbors;

    ostringstream oss;

    oss << id;

    string idString = oss.str();

    regex patternSource(idString + "-[[:alnum:]]+");

    for (auto it = edges.begin(); it != edges.end();)
    {
        if (regex_match(it->first, patternSource))
        {
            neighbors.push_back(it->second.getDestination());
        }
        it++;
    }

    return neighbors;
}

/**
 * @brief This method is to make a depth first search in the graph.
 *
 * @tparam K                    Key is the type of the key of the node.
 * @tparam T                    Data is the data of the node.
 * @param id                    The id of the node to start the search.
 * @return vector<Node<K, T>>   A vector with the nodes visited.
 */
template <typename K, typename T>
vector<Node<K, T>> Graph<K, T>::depthFirstSearch(K id)
{
    vector<Node<K, T>> result;
    return depthFirstSearchHelper(id, result);
}

/**
 * @brief This method is to make a depth first search in the graph.
 *
 * @tparam K                    Key is the type of the key of the node.
 * @tparam T                    Data is the data of the node.
 * @param id                    The id of the current node.
 * @param result                A vector to store the nodes visited.
 * @return vector<Node<K, T>>   A vector with the nodes visited.
 */
template <typename K, typename T>
vector<Node<K, T>> Graph<K, T>::depthFirstSearchHelper(K id, vector<Node<K, T>> &result)
{
    Node<K, T> node = nodes.find(id)->second;

    result.push_back(node);

    for (auto edge : edges)
    {
        /**
         * The condition checks if the source (source) of the edge (edge) has the same id as
         * the current node (id), that is, if the edge is connected to the current node. If
         * the condition is met, it is checked if the destination node of the edge is already
         * in the result vector using the std::find function.
         *
         * If the destination node is not in result, it is added to the vector and
         * depthFirstSearchHelper is called recursively with the id of the destination
         * node to continue the depth search. In this way, it is guaranteed that each node is
         * visited only once during the in-depth traversal of the graph.
         */

        if (edge.second.getSource().getId() == id &&
            find(result.begin(), result.end(), edge.second.getDestination()) == result.end())
        {
            depthFirstSearchHelper(edge.second.getDestination().getId(), result);
        }
    }
    return result;
}

/**
 * @brief This method is to make a breadth first search in the graph.
 *
 * @tparam K                    Key is the type of the key of the node.
 * @tparam T                    Data is the data of the node.
 * @param id                    The id of the node to start the search.
 * @return vector<Node<K, T>>   A vector with the nodes visited.
 */
template <typename K, typename T>
vector<Node<K, T>> Graph<K, T>::breadthFirstSearch(K id)
{
    vector<Node<K, T>> result;
    return breadthFirstSearchHelper(id, result);
}

/**
 * @brief This method is to make a breadth first search in the graph.
 *
 * @tparam K                    Key is the type of the key of the node.
 * @tparam T                    Data is the data of the node.
 * @param id                    The id of the node to start the search.
 * @param result                A vector to store the nodes visited.
 * @return vector<Node<K, T>>   A vector with the nodes visited.
 */
template <typename K, typename T>
vector<Node<K, T>> Graph<K, T>::breadthFirstSearchHelper(K id, vector<Node<K, T>> &result)
{
    /**
     * The function starts by finding the node with key "id" in the graph and inserts it into a queue.
     * Then, as long as the queue is not empty, the function performs the following steps:
     *
     * 1.Takes the first element of the queue, which is the next node to visit in the width traversal.
     *
     * 2.Add this node to the "result" vector.
     *
     * 3.For each edge of the graph, it checks if the current node is the source node of the edge and if
     * the destination node of the edge has not yet been visited (it is not in "result"). If this is true,
     * it adds the destination node to the queue to visit later.
     *
     * 4.Repeat steps 1-3 for the next node in the queue.
     *
     */

    Node<K, T> sourceNode = nodes.find(id)->second;
    queue<Node<K, T>> queue;

    queue.push(sourceNode);

    while (!queue.empty())
    {
        Node<K, T> node = queue.front();
        queue.pop();

        result.push_back(node);

        for (auto edge : edges)
        {
            if (edge.second.getSource().getId() == node.getId() &&
                find(result.begin(), result.end(), edge.second.getDestination()) == result.end())
            {
                queue.push(edge.second.getDestination());
            }
        }
    }

    return result;
}