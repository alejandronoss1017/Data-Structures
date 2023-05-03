/**
 * @brief Construct a new Node object
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 */
template <typename K, typename T>
Node<K, T>::Node() = default;

/**
 * @brief Construct a new Node object
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @param data      is the data of the node.
 */
template <typename K, typename T>
Node<K, T>::Node(T data)
{
    Node<K, T>::data = data;
}

/**
 * @brief Construct a new Node object
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @param id        is the id of the node.
 * @param matrixId  is the id of the matrix where the node is.
 * @param data      is the data of the node.
 */
template <typename K, typename T>
Node<K, T>::Node(K id, int matrixId, T data)
{
    Node::id = id;
    Node::matrixId = matrixId;
    Node::data = data;
}

/**
 * @brief Destroy the Node object
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 */
template <typename K, typename T>
Node<K, T>::~Node() = default;

/**
 * @brief Gets the id of the node.
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @return K        is the id of the node.
 */
template <typename K, typename T>
K Node<K, T>::getId() const
{
    return id;
}

/**
 * @brief Sets the id of the node.
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @param id        is the id of the node.
 */
template <typename K, typename T>
void Node<K, T>::setId(K id)
{
    Node::id = id;
}

/**
 * @brief Gets the id of the matrix where the node is.
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @return int      is the id of the matrix where the node is.
 */
template <typename K, typename T>
int Node<K, T>::getMatrixId() const
{
    return matrixId;
}

/**
 * @brief Sets the id of the matrix where the node is.
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @param matrixId  is the id of the matrix where the node is.
 */
template <typename K, typename T>
void Node<K, T>::setMatrixId(int matrixId)
{
    Node::matrixId = matrixId;
}

/**
 * @brief Gets the data of the node.
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @return T        is the data of the node.
 */
template <typename K, typename T>
T Node<K, T>::getData() const
{
    return data;
}

/**
 * @brief Sets the data of the node.
 *
 * @tparam K        is the type of the Id of the node.
 * @tparam T        is the type of the data of the node.
 * @param data      is the data of the node.
 */
template <typename K, typename T>
void Node<K, T>::setData(T data)
{
    Node::data = data;
}

/**
 * @brief Overloads the operator == to compare two nodes.
 *
 * @tparam K            is the type of the Id of the node.
 * @tparam T            is the type of the data of the node.
 * @param otherNode     is the node to compare.
 * @return true         if the nodes are equal.
 * @return false        if the nodes are not equal.
 */
template <typename K, typename T>
bool Node<K, T>::operator==(const Node<K, T> &otherNode) const
{
    return id == otherNode.id &&
           matrixId == otherNode.matrixId &&
           data == otherNode.data;
}

/**
 * @brief Overloads the operator != to compare two nodes.
 *
 * @tparam K            is the type of the Id of the node.
 * @tparam T            is the type of the data of the node.
 * @param otherNode     is the node to compare.
 * @return true         if the nodes are equal.
 * @return false        if the nodes are not equal.
 */
template <typename K, typename T>
bool Node<K, T>::operator!=(const Node<K, T> &otherNode) const
{
    return !(otherNode == *this);
}

/**
 * @brief Overloads the operator << to print a node.
 *
 * @tparam U            is the type of the Id of the node.
 * @tparam L            is the type of the data of the node.
 * @param os            is the output stream.
 * @param node          is the node to print.
 * @return ostream&     is the output stream.
 */
template <typename U, typename L>
ostream &operator<<(ostream &os, const Node<U, L> &node)
{
    os << "{"
       << "id: " << node.id << " matrixId: " << node.matrixId << " data: " << node.data
       << "}";
    return os;
}
