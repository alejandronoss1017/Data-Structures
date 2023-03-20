
/**
 * @brief Construct a new AVLTree with nullptr root.
 *
 * @tparam T Type of data stored in the tree.
 */
template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

/**
 * @brief Construct a new AVLTree with a root value.
 *
 * @tparam T Type of data stored in the tree.
 * @param data Value to be inserted on the AVLTree root.
 */
template <typename T>
AVLTree<T>::AVLTree(const T &data)
{
    root = new AVLNode<T>(data);
}

/**
 * @brief Destroy a AVLTree.
 *
 * @tparam T Type of data stored in the tree.
 */
template <typename T>
AVLTree<T>::~AVLTree() = default;

/**
 * @brief Private method to create a new AVLNode and
 * insert it into the right position. Once the AVLNode is
 * inserted the AVLTree will update all nodes heights and
 * do balance.
 *
 * @tparam T Type of data stored in the tree.
 * @param node Root of the AVLTree to be inserted the new AVLNode.
 * @param data Value to be inserted inside the new AVLNode.
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::insertHelper(AVLNode<T> *node, const T &data)
{

    // If the AVLNode is nullptr create a new one
    if (node == nullptr)
    {
        return new AVLNode<T>(data);
    }

    // If data is less than node->data, search in left nodes
    if (data < node->getData())
    {
        node->setLeftChild(insertHelper(node->getLeftChild(), data));
    }
    // If data is greater than node->data, search in right nodes
    else if (data > node->getData())
    {
        node->setRightChild(insertHelper(node->getRightChild(), data));
    }
    // If element already exist return the node itself
    else
    {
        return node;
    }

    //  After insertion update all nodes heights and do balance
    updateHeight(node);

    return balance(node);
}

/**
 * @brief Private method to remove a AVLNode that's inside
 * the AVLTree. Once the AVLNode is removed the AVLTree will
 *  update all nodes heights and do balance.
 *
 * @tparam T Type of data stored in the tree.
 * @param node Root of the AVLTree to remove a AVLNode.
 * @param data Value to be find inside the AVLTree and removed.
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::removeHelper(AVLNode<T> *node, const T &data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    // If data is less than node->data, search in left nodes and set a pointer
    else if (data < node->getData())
    {
        node->setLeftChild(removeHelper(node->getLeftChild(), data));
    }
    // If data is greater than node->data, search in right nodes and set a pointer
    else if (data > node->getData())
    {
        node->setRightChild(removeHelper(node->getRightChild(), data));
    }
    // Once the node is founded
    else
    {
        // If is a leaf just delete that node and return nullptr
        if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr)
        {
            delete node;
            node = nullptr;
            return node;
        }
        // If that node just have one child
        else if (node->getLeftChild() == nullptr)
        {
            AVLNode<T> *temp = node;
            node = node->getRightChild();
            delete temp;
            return node;
        }
        else if (node->getRightChild() == nullptr)
        {
            AVLNode<T> *temp = node;
            node = node->getLeftChild();
            delete temp;
            return node;
        }
        else
        {
            AVLNode<T> *maxNode = findLargestNode(node->getLeftChild());
            node->setData(maxNode->getData());
            node->setLeftChild(removeHelper(node->getLeftChild(), maxNode->getData()));
        }
    }
    return balance(node);
}

/**
 * @brief Private method that finds the smallest value in a AVLNode
 * inside a AVLTree.
 *
 * @tparam T Type of data stored in the tree.
 * @param node Root of the AVLTree to search.
 * @return BinaryNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::findSmallestNode(AVLNode<T> *node)
{
    /*  This could be implemented in a recursive form also, but I prefer
    in an iterative form because where are just moving in the right child*/
    while (node != nullptr && node->getLeftChild() != nullptr)
    {
        node = node->getLeftChild();
    }
    return node;
}

/**
 * @brief Private method that finds the largest value in a AVLNode
 * inside a AVLTree.
 *
 * @tparam T Type of data stored in the tree.
 * @param node Root of the AVLTree to search.
 * @return BinaryNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::findLargestNode(AVLNode<T> *node)
{
    /*  This could be implemented in a recursive form also, but I prefer
    in an iterative form because where are just moving in the right child*/
    while (node != nullptr && node->getRightChild() != nullptr)
    {
        node = node->getRightChild();
    }
    return node;
}

/**
 * @brief Private method that gets the height of a AVLNode.
 *
 * @tparam T Type of data stored in the tree.
 * @param node AVLNode to get the height.
 * @return int Height of the AVLNode.
 */
template <typename T>
int AVLTree<T>::heightHelper(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    return node->getHeight();
}

/**
 * @brief Private method that calculate the height of a AVLNode.
 *
 * @tparam T Type of data stored in the tree.
 * @param node AVLNode to calculate the height.
 */
template <typename T>
void AVLTree<T>::updateHeight(AVLNode<T> *node)
{
    int leftHeight = heightHelper(node->getLeftChild());
    int rightHeight = heightHelper(node->getRightChild());
    node->setHeight(max(leftHeight, rightHeight) + 1);
}

/**
 * @brief Private method that calculates the balance factor of
 * a given node, which is defined as the difference between the
 *  heights of its left and right subtrees.
 *
 * @tparam T Type of data stored in the tree.
 * @param node AVLNode to calculate the height.
 * @return int balance factor
 */
template <typename T>
int AVLTree<T>::balanceFactor(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = heightHelper(node->getLeftChild());
    int rightHeight = heightHelper(node->getRightChild());

    return leftHeight - rightHeight;
}

/**
 * @brief Private method that checks if a given node is empty.
 *
 * @tparam T Type of data stored in the tree
 * @param node Root of the AVLTree
 * @return true If is null
 * @return false If isn't null
 */
template <typename T>
bool AVLTree<T>::emptyHelper(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Private method that deletes all nodes of the AVLTree
 *  starting from a given node.
 *
 * @tparam T Type of data stored in the tree
 * @param node Root of the AVLTree
 */
template <typename T>
void AVLTree<T>::clearHelper(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        clearHelper(node->getLeftChild());
        clearHelper(node->getRightChild());
        node->~AVLNode();
    }
}

/**
 * @brief Private method that checks if two nodes are equal.
 *
 * @tparam T Type of data stored in the tree
 * @param node1 First AVLNode to compare
 * @param node2 Second AVLNode to compare
 * @return true If both are equals
 * @return false If aren't equals
 */
template <typename T>
bool AVLTree<T>::equals(const AVLNode<T> *node1, const AVLNode<T> *node2) const
{
    if (node1 == nullptr && node2 == nullptr)
    {
        return true;
    }
    if (node1 == nullptr || node2 == nullptr)
    {
        return false;
    }

    return node1->getData() == node2->getData() &&
           equals(node1->getLeftChild(), node2->getLeftChild()) &&
           equals(node1->getRightChild(), node2->getRightChild());
}

/**
 * @brief Private method that balances a given node by
 * performing rotations if its balance factor is greater
 * than one or less than negative one.
 *
 * @tparam T Type of data stored in the tree
 * @param node AVLNode to check the balance
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::balance(AVLNode<T> *node)
{
    int bf = balanceFactor(node);

    /**
     * If the difference in height is 2 or -2, we need to rotate
     *
     * If the left subtree is 2 units taller than the right subtree,
     * we enter the left node
     *
     * We check the height of that node, which is the difference in
     * height between the left and right child nodes
     *
     * If the difference > 0, rotate to the right
     * If the difference < 0, double rotation right
     *
     * If the right subtree is 2 units taller than the left subtree,
     * We enter the right node
     *
     * If the difference is > 0, rotate to the left
     * If the difference < 0, double rotation left
     */

    if (bf > 1)
    {

        if (balanceFactor(node->getLeftChild()) < 0)
        {
            node->setLeftChild(rotateLeft(node->getLeftChild()));
        }
        return rotateRight(node);
    }
    else if (bf < -1)
    {
        if (balanceFactor(node->getRightChild()) > 0)
        {
            node->setRightChild(rotateRight(node->getRightChild()));
        }
        return rotateLeft(node);
    }

    return node;
}

/**
 * @brief Private method that performs a right rotation on a given node.
 *
 * @tparam T Type of data stored in the tree
 * @param node ALVNode to do the rotation
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::rotateRight(AVLNode<T> *node)
{
    AVLNode<T> *parent = node->getLeftChild();
    node->setLeftChild(parent->getRightChild());
    parent->setRightChild(node);

    updateHeight(node);
    updateHeight(parent);

    return parent;
}

/**
 * @brief Private method that performs a left rotation on a given node.
 *
 * @tparam T Type of data stored in the tree
 * @param node ALVNode to do the rotation
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::rotateLeft(AVLNode<T> *node)
{
    AVLNode<T> *parent = node->getRightChild();
    node->setRightChild(parent->getLeftChild());
    parent->setLeftChild(node);

    updateHeight(node);
    updateHeight(parent);
    return parent;
}

/**
 * @brief Private method that copies a AVLTree starting from a given node.
 *
 * @tparam T Type of data stored in the tree
 * @param node Root of the AVLTree
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::copyTree(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }

    auto *newNode = new AVLNode<T>(node->getData(), node->getHeight(),
                                   node->getLeftChild(), node->getRightChild());

    return newNode;
}

/**
 * @brief Private method that finds a node with a given value
 * starting from a given node.
 *
 * @tparam T Type of data stored in the tree
 * @param node Root of the AVLTree
 * @param data Value of the AVLNode
 * @return true If a AVLNode is founded with that value
 * @return false If a AVLNode isn't founded with that value
 */
template <typename T>
bool AVLTree<T>::findNodeHelper(AVLNode<T> *node, const T &data) const
{

    if (node == nullptr)
    {
        return false;
    }

    if (node->getData() == data)
    {
        return true;
    }
    else if (data < node->getData())
    {
        return findNodeHelper(node->getLeftChild(), data);
    }
    else
    {
        return findNodeHelper(node->getRightChild(), data);
    }
    return false;
}

/**
 * @brief Private method that traverses the AVLTree in in-order
 * and outputs the data of each node, by default is used in the
 * '<<' operator of the AVLTree.
 *
 * @tparam T Type of data stored in the tree
 * @param node Root of the AVLTree
 * @param os Output stream
 */
template <typename T>
void AVLTree<T>::traverseInOrderHelper(AVLNode<T> *node, ostream &os) const
{
    if (node == nullptr)
    {
        return;
    }

    traverseInOrderHelper(node->getLeftChild(), os);
    os << node->getData() << " ";
    traverseInOrderHelper(node->getRightChild(), os);
}

/**
 * @brief Private  method that traverses the tree in pre-order
 * and outputs the data of each node.
 *
 * @tparam T Type of data stored in the tree
 * @param node Root of the AVLTree
 */
template <typename T>
void AVLTree<T>::traversePreOrderHelper(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->getData() << " ";
    traversePreOrderHelper(node->getLeftChild());
    traversePreOrderHelper(node->getRightChild());
}

/**
 * @brief Private method that traverses the tree in post-order
 * and outputs the data of each node.
 *
 * @tparam T Type of data stored in the tree
 * @param node Root of the AVLTree
 */
template <typename T>
void AVLTree<T>::traversePostOrderHelper(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return;
    }
    traversePreOrderHelper(node->getLeftChild());
    traversePreOrderHelper(node->getRightChild());
    cout << node->getData() << " ";
}

/**
 * @brief Inserts a new node with the given data in the AVL tree.
 *
 * @tparam T Type of data stored in the tree
 * @param data Value to be inserted in the AVLTree.
 * @return true If the node was successfully inserted.
 * @return false If the node could not be inserted due to memory allocation failure *
 */
template <typename T>
bool AVLTree<T>::insert(const T &data)
{
    if (root == nullptr)
    {
        root = new AVLNode<T>(data);
        return true;
    }

    int prevHeight = root->getHeight();
    root = insertHelper(root, data);
    int newHeight = root->getHeight();
    return newHeight > prevHeight;
}

/**
 * @brief Returns the height of the AVL tree.
 *
 * @tparam T Type of data stored in the tree.
 * @return int The height of the AVL tree.
 */
template <typename T>
int AVLTree<T>::height() const
{
    if (root == nullptr)
    {
        return 0;
    }

    return root->getHeight();
}

/**
 * @brief Copy assignment operator for AVLTree.
 *
 * @tparam T Type of data stored in the tree.
 * @param otherTree The tree to copy.
 * @return AVLTree& The updated tree after copy assignment.
 */
template <typename T>
AVLTree<T> &AVLTree<T>::operator=(const AVLTree<T> &otherTree)
{
    // Avoid self-assignment
    if (this == &otherTree)
    {
        return *this;
    }

    // Delete current tree and copy other tree
    delete (root);
    root = copyTree(otherTree.root);

    return *this;
}

/**
 * @brief Overloaded equality operator for AVLTree.
 *
 * @tparam T Type of data stored in the tree.
 * @param otherTree The tree to compare with.
 * @return true If the trees are equal.
 * @return false If the trees are not equal.
 */
template <typename T>
bool AVLTree<T>::operator==(const AVLTree<T> &otherTree) const
{
    return equals(root, otherTree.root);
}

/**
 * @brief Overloaded inequality operator for AVLTree.
 *
 * @tparam T Type of data stored in the tree.
 * @param otherTree The tree to compare with.
 * @return true If the trees are not equal.
 * @return false If the trees are equal.
 */
template <typename T>
bool AVLTree<T>::operator!=(const AVLTree<T> &otherTree) const
{
    /**
     * Use the == overload to compare if the trees are different, it
     * will return true, if are equals return false.
     */
    return !(*this == otherTree);
}

/**
 * @brief Overloaded less than operator for AVLTree.
 * Compares the heights of the trees.
 *
 * @tparam T Type of data stored in the tree.
 * @param otherTree The tree to compare with.
 * @return true If the height of this tree is less than the height of the other tree.
 * @return false If the height of this tree is greater than or equal to the height of the other tree.
 */
template <typename T>
bool AVLTree<T>::operator<(const AVLTree &otherTree) const
{
    return root->getHeight() < otherTree.root->getHeight();
}

/**
 * @brief Overloaded greater than operator for AVLTree. Compares the heights of the trees.
 *
 * @tparam T Type of data stored in the tree.
 * @param otherTree The tree to compare with.
 * @return true If the height of this tree is greater than the height of the other tree.
 * @return false If the height of this tree is less than or equal to the height of the other tree.
 */
template <typename T>
bool AVLTree<T>::operator>(const AVLTree &otherTree) const
{
    return root->getHeight() > otherTree.root->getHeight();
}

/**
 * @brief Overloaded less than or equal to operator for AVLTree. Compares the heights of the trees.
 *
 * @tparam T Type of data stored in the tree.
 * @param otherTree The tree to compare with.
 * @return true If the height of this tree is less than or equal to the height of the other tree.
 * @return false If the height of this tree is greater than the height of the other tree.
 */
template <typename T>
bool AVLTree<T>::operator<=(const AVLTree &otherTree) const
{
    return !(root->getHeight() < otherTree.root->getHeight());
}

/**
 * @brief Overloaded greater than or equal to operator for AVLTree.
 * Compares the heights of the trees.
 *
 * @tparam T Type of data stored in the tree.
 * @param otherTree The tree to compare with.
 * @return true If the height of this tree is greater than or equal to the height of the other tree.
 * @return false If the height of this tree is less than the height of the other tree.
 */
template <typename T>
bool AVLTree<T>::operator>=(const AVLTree &otherTree) const
{
    return !(root->getHeight() > otherTree.root->getHeight());
}

/**
 * @brief Removes a node with the specified data from the tree.
 *
 * @tparam T Type of data stored in the tree.
 * @param data The data to remove from the tree.
 * @return true If the node is successfully removed.
 * @return false If the node is not found in the tree.
 */
template <typename T>
bool AVLTree<T>::remove(const T &data)
{
    int prevHeight = root->getHeight();
    root = removeHelper(root, data);
    int newHeight = root->getHeight();
    return newHeight < prevHeight;
}
/**
 * @brief Deletes all nodes in the tree and sets root to nullptr.
 *
 * @tparam T Type of data stored in the tree.
 */
template <typename T>
void AVLTree<T>::clear()
{
    clearHelper(root);
    root = nullptr;
}

/**
 * @brief Determines whether the specified data is in the tree.
 *
 * @tparam T Type of data stored in the tree.
 * @param data The data to search for in the tree.
 * @return true If the data is found in the tree.
 * @return false If the data is not found in the tree.
 */
template <typename T>
bool AVLTree<T>::find(const T &data) const
{
    if (findNodeHelper(root, data))
    {
        return true;
    }

    return false;
}

/**
 * @brief Traverses the tree in pre-order and prints the data of each node.
 *
 * @tparam T Type of data stored in the tree.
 */
template <typename T>
void AVLTree<T>::traversePreOrder()
{
    traversePreOrderHelper(root);
}

/**
 * @brief Traverses the tree in post-order and prints the data of each node.
 *
 * @tparam T Type of data stored in the tree.
 */
template <typename T>
void AVLTree<T>::traversePostOrder()
{
    traversePostOrderHelper(root);
}

/**
 * @brief Determines whether the tree is empty.
 *
 * @tparam T Type of data stored in the tree.
 * @return true If the tree is empty.
 * @return false If the tree is not empty.
 */
template <typename T>
bool AVLTree<T>::empty() const
{
    return emptyHelper(root);
}

/**
 * @brief Returns the smallest value stored in the tree.
 *
 * @tparam T Type of data stored in the tree.
 * @return T The smallest value stored in the tree.
 */
template <typename T>
T AVLTree<T>::smallest()
{
    return T(findSmallestNode(root)->getData());
}

/**
 * @brief Returns the largest value stored in the tree.
 *
 * @tparam T Type of data stored in the tree.
 * @return T The largest value stored in the tree.
 */
template <typename T>
T AVLTree<T>::largest()
{
    return T(findLargestNode(root)->getData());
}

/**
 * @brief Overloaded insertion operator for AVLTree.
 *
 * @tparam U Type of data stored in the tree.
 * @param os The output stream to write to.
 * @param tree The AVLTree to be written to the output stream.
 * @return ostream& The output stream after writing the AVLTree to it.
 */
template <typename U>
ostream &operator<<(ostream &os, const AVLTree<U> &tree)
{
    tree.traverseInOrderHelper(tree.root, os);
    return os;
}