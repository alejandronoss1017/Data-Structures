/**
 * @brief Construct a new Edge object
 *
 * @tparam K        Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T        Data is the type of the data of the node.
 */
template <typename K, typename T>
Edge<K, T>::Edge() = default;

/**
 * @brief Construct a new Edge object
 *
 * @tparam K            Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T            Data is the type of the data of the node.
 * @param id            Id of the edge.
 * @param weight        Weight of the edge.
 * @param source        Source node of the edge.
 * @param destination   Destination node of the edge.
 */
template <typename K, typename T>
Edge<K, T>::Edge(const string &id, double weight, const Node<K, T> &source, const Node<K, T> &destination)
{
    /*!
        Idk why it should be a empty constructor, in node class for using this constructor.

        If theres no empty constructor, it gives this error:

        'no matching function for call to 'Node<std::__cxx11::basic_string<char> >::Node()'

        If still no wanted an empty constructor in node class, use a initializer list in this constructor,
        this also works.
    */
    Edge<K, T>::id = id;
    Edge<K, T>::weight = weight;
    Edge<K, T>::source = source;
    Edge<K, T>::destination = destination;
}

/**
 * @brief Destroy the Edge Edge object
 *
 * @tparam K        Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T        Data is the type of the data of the node.
 */
template <typename K, typename T>
Edge<K, T>::~Edge() = default;

/**
 * @brief Get the Id object of the edge.
 *
 * @tparam K                    Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T                    Data is the type of the data of the node.
 * @return const string&        Id of the edge.
 */
template <typename K, typename T>
const string &Edge<K, T>::getId() const
{
    return id;
}

/**
 * @brief Set the Id object of the edge.
 *
 * @tparam K                    Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T                    Data is the type of the data of the node.
 * @param id                    Id of the edge.
 */
template <typename K, typename T>
void Edge<K, T>::setId(const string &id)
{
    Edge<K, T>::id = id;
}

/**
 * @brief Get the Weight object of the edge.
 *
 * @tparam K            Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T            Data is the type of the data of the node.
 * @return double       Weight of the edge.
 */
template <typename K, typename T>
double Edge<K, T>::getWeight() const
{
    return weight;
}

/**
 * @brief Set the Weight object of the edge.
 *
 * @tparam K            Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T            Data is the type of the data of the node.
 * @param weight        Weight of the edge.
 */
template <typename K, typename T>
void Edge<K, T>::setWeight(double weight)
{
    Edge<K, T>::weight = weight;
}

/**
 * @brief Get the Source object of the edge.
 *
 * @tparam K                    Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T                    Data is the type of the data of the node.
 * @return const Node<K, T>&    Source node of the edge.
 */
template <typename K, typename T>
const Node<K, T> &Edge<K, T>::getSource() const
{
    return source;
}

/**
 * @brief Set the Source object of the edge.
 *
 * @tparam K                Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T                Data is the type of the data of the node.
 * @param source            Source node of the edge.
 */
template <typename K, typename T>
void Edge<K, T>::setSource(const Node<K, T> &source)
{
    Edge<K, T>::source = source;
}

/**
 * @brief Get the Destination object of the edge.
 *
 * @tparam K                    Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T                    Data is the type of the data of the node.
 * @return const Node<K, T>&    Destination node of the edge.
 */
template <typename K, typename T>
const Node<K, T> &Edge<K, T>::getDestination() const
{
    return destination;
}

/**
 * @brief Set the Destination object of the edge.
 *
 * @tparam K                Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T                Data is the type of the data of the node.
 * @param destination       Destination node of the edge.
 */
template <typename K, typename T>
void Edge<K, T>::setDestination(const Node<K, T> &destination)
{
    Edge<K, T>::destination = destination;
}

/**
 * @brief Overload of the operator << for the Edge class.
 *
 * @tparam U                Key is the type of the key of the nodes map, same type as node Id.
 * @tparam L                Data is the type of the data of the node.
 * @param os                ostream object.
 * @param edge              Edge object.
 * @return ostream&         ostream object.
 */
template <typename U, typename L>
ostream &operator<<(ostream &os, const Edge<U, L> &edge)
{
    os << "Edge: {" << edge.id << " weight: " << edge.weight << " source: " << edge.source << " destination: " << edge.destination << "}";
    return os;
}
