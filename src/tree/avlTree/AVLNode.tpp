
/**
 * @brief Construct a new AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @param data Value of the AVLNode.
 */
template <typename T>
AVLNode<T>::AVLNode(const T &data)
{
    this->data = data;
    this->height = 1;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

/**
 * @brief Construct a new AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @param data Value of the AVLNode.
 * @param height Height of the AVLNode.
 * @param leftChild Pointer to the left child of the main AVLNode.
 * @param rightChild Pointer to the right child of the main AVLNode.
 */
template <typename T>
AVLNode<T>::AVLNode(const T &data, int height, AVLNode<T> *leftChild, AVLNode<T> *rightChild)
{
    this->data = data;
    this->height = height;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
}
/**
 * @brief Destroy a AVLNode.
 *
 * @tparam T Primitive types or classes.
 */
template <typename T>
AVLNode<T>::~AVLNode() = default;

/**
 * @brief Gets the value of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @return T Value of the Binary Node.
 */
template <typename T>
T AVLNode<T>::getData() const
{
    return data;
}

/**
 * @brief Sets the value of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @param data Value to be inserted into the AVLNode.
 */
template <typename T>
void AVLNode<T>::setData(T data)
{
    AVLNode::data = data;
}

/**
 * @brief Gets the height of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @return int Height of a AVLNode.
 */
template <typename T>
int AVLNode<T>::getHeight() const
{
    return height;
}

/**
 * @brief Sets the height of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @param height Height to be inserted into the AVLNode.
 */
template <typename T>
void AVLNode<T>::setHeight(int height)
{
    AVLNode::height = height;
}

/**
 * @brief Gets the pointer to the left child of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLNode<T>::getLeftChild() const
{
    return leftChild;
}

/**
 * @brief Sets a AVLNode pointer to the left child of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @param node AVLNode to be inserted.
 */
template <typename T>
void AVLNode<T>::setLeftChild(AVLNode<T> *leftChild)
{
    AVLNode::leftChild = leftChild;
}

/**
 * @brief Gets the pointer to the right child of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLNode<T>::getRightChild() const
{
    return rightChild;
}

/**
 * @brief Sets a AVLNode pointer to the right child of a AVLNode.
 *
 * @tparam T Primitive types or classes.
 * @param node AVLNode to be inserted.
 */
template <typename T>
void AVLNode<T>::setRightChild(AVLNode<T> *rightChild)
{
    AVLNode::rightChild = rightChild;
}
