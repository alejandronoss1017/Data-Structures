template <typename T>
Node<T>::Node() = default;

template <typename T>
Node<T>::Node(T data)
{
    Node<T>::data = data;
}

template <typename T>
Node<T>::Node(string id, int matrixId, T data)
{
    Node::id = id;
    Node::matrixId = matrixId;
    Node::data = data;
}

template <typename T>
Node<T>::~Node() = default;

template <typename T>
string Node<T>::getId() const
{
    return id;
}

template <typename T>
void Node<T>::setId(string id)
{
    Node::id = id;
}

template <typename T>
int Node<T>::getMatrixId() const
{
    return matrixId;
}

template <typename T>
void Node<T>::setMatrixId(int matrixId)
{
    Node::matrixId = matrixId;
}

template <typename T>
T Node<T>::getData() const
{
    return data;
}

template <typename T>
void Node<T>::setData(T data)
{
    Node::data = data;
}
template <typename T>
bool Node<T>::operator==(const Node &rhs) const
{
    return id == rhs.id &&
           matrixId == rhs.matrixId &&
           data == rhs.data;
}
template <typename T>

bool Node<T>::operator!=(const Node &rhs) const
{
    return !(rhs == *this);
}

template <typename U>
ostream &operator<<(ostream &os, const Node<U> &node)
{
    os << "["
       << "id: " << node.id << " matrixId: " << node.matrixId << " data: " << node.data
       << "]";
    return os;
}