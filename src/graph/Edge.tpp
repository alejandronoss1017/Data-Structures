template <typename T>
Edge<T>::Edge(const string &id, double weight, const Node<T> &source, const Node<T> &destination)
{
    /*!
        Idk why it should be a empty constructor, in node class for using this constructor.

        If theres no empty constructor, it gives this error:

        'no matching function for call to 'Node<std::__cxx11::basic_string<char> >::Node()'

        If still no wanted an empty constructor in node class, use a initializer list in this constructor,
        this also works.
    */
    Edge<T>::id = id;
    Edge<T>::weight = weight;
    Edge<T>::source = source;
    Edge<T>::destination = destination;
}

template <typename U>
ostream &operator<<(ostream &os, const Edge<U> &edge)
{
    os << "Edge: " << edge.id << " weight: " << edge.weight << " source: " << edge.source << " destination: " << edge.destination;
    return os;
}
