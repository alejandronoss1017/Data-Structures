
/**
 * @brief Construct a new Binary Tree object with
 * null root.
 *
 * @tparam T primitive types or classes.
 */
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

/**
 * @brief Construct a new Binary Tree object
 * with a root data.
 *
 * @tparam T primitive types or classes.
 * @param data value to be inserted in the root.
 */
template <typename T>
BinaryTree<T>::BinaryTree(const T &data)
{
    root = new BinaryNode<T>(data);
}

/**
 * @brief Destructor of a Binary Tree object
 *
 * @tparam T primitive types or classes
 */
template <typename T>
BinaryTree<T>::~BinaryTree()
{
    deleteTree(root);
}

/**
 * @brief Insert a new node with a value,
 *  it will be inserted by the value of the data
 *
 * @param data value to be inserted
 * @return true if the insertion was successful or false if can't do the insertion.
 */
template <typename T>
bool BinaryTree<T>::insert(const T &data)
{

    if (root == nullptr)
    {
        root = new BinaryNode<T>(data);
        return true;
    }
    else
    {
        if (insertNode(data, root))
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Removes the specified Binary Tree node
 *
 * @tparam T primitive types or classes
 * @param data value of the node to be removed.
 *
 */
template <typename T>
bool BinaryTree<T>::remove(const T &data)
{
    return deleteNodeHelper(data, root);
}

template <typename T>
bool BinaryTree<T>::find(const T &data)
{
    if (findNodeHelper(data, root))
    {
        return true;
    }
    return false;
}

/**
 * @brief Private method to create a new Binary Tree node and insert it into the right position
 *
 * @tparam T Primitive types or classes
 * @param data Value to be inserted inside the Binary Tree node.
 * @param node Root of the Binary Tree to search the right position.
 */
template <typename T>
bool BinaryTree<T>::insertNode(const T &data, BinaryNode<T> *node)
{
    /*  Reminder: if it's a pointer we need to use pointer annotations  */
    if (data < node->getData())
    {
        if (node->getLeftChild() == nullptr)
        {
            node->setLeftChild(new BinaryNode<T>(data));
            return true;
        }
        else
        {
            return insertNode(data, node->getLeftChild());
        }
    }
    else if (data > node->getData())
    {
        if (node->getRightChild() == nullptr)
        {
            node->setRightChild(new BinaryNode<T>(data));
            return true;
        }
        else
        {
            return insertNode(data, node->getRightChild());
        }
    }
    else
    {
        return false;
    }
    return false;
}

/**
 * @brief Private method that print a Binary Tree in a pre-order way.
 *
 * @tparam T Primitive types or classes
 * @param node Root of the Binary Tree to print.
 */
template <typename T>
void BinaryTree<T>::traversePreOrderHelper(BinaryNode<T> *node)
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
 * @brief Private method that print a Binary Tree in a In-order way.
 * By default is the << operator overload of the Binary Tree.
 *
 * @tparam T Primitive types or classes.
 * @param node Root of the Binary Tree to print.
 * @param os Output Stream.
 */
template <typename T>
void BinaryTree<T>::traverseInOrderHelper(BinaryNode<T> *node, ostream &os) const
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
 * @brief Private method that print a Binary Tree in a Post-order way.
 *
 * @tparam T Primitive types or classes
 * @param node Root of the Binary Tree to print.
 */
template <typename T>
void BinaryTree<T>::traversePostOrderHelper(BinaryNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }

    traversePostOrderHelper(node->getLeftChild());
    traversePostOrderHelper(node->getRightChild());
    cout << node->getData() << " ";
}

/**
 * @brief Private method that deletes a Binary Tree
 *
 * @tparam T Primitive types or classes
 * @param node Root of the Binary Tree to delete.
 */
template <typename T>
void BinaryTree<T>::deleteTree(BinaryNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->getLeftChild());
    deleteTree(node->getRightChild());
    delete node;
}

/**
 * @brief Private method that search for an specified Binary Tree node, once is founded the node is deleted.
 *
 * @tparam T Primitive types or classes
 * @param data Value of the node to be removed.
 * @param node Root of the Binary Tree to search a node for be remove.
 * @return BinaryNode<T>*
 */
template <typename T>
bool BinaryTree<T>::deleteNodeHelper(const T &data, BinaryNode<T> *node)
{
    if (node == nullptr)
    {
        return false;
    }

    if (data < node->getData())
    {
        if (deleteNodeHelper(data, node->getLeftChild()))
        {
            node->setLeftChild(nullptr);
            return true;
        }
        return false;
    }
    else if (data > node->getData())
    {
        if (deleteNodeHelper(data, node->getRightChild()))
        {
            node->setRightChild(nullptr);
            return true;
        }
        return false;
    }
    else
    {
        // If the node to eliminate doesn't have any child
        if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr)
        {
            delete node;
            node = nullptr;
            return true;
        }

        /**
         * If the node to be deleted has only one non-null child,
         * the node to be deleted is replaced with its child,
         * and the node to be deleted is deleted.
         */
        else if (node->getLeftChild() == nullptr)
        {
            BinaryNode<T> *temp = node;
            node = node->getRightChild();
            delete temp;
            return true;
        }
        else if (node->getRightChild() == nullptr)
        {
            BinaryNode<T> *temp = node;
            node = node->getLeftChild();
            delete temp;
            return true;
        }
        /**
         * If the node to eliminate have both child,
         * search for the largest node in the left child
         * of the node to eliminate, then change nodes.
         */
        else
        {
            BinaryNode<T> *temp = findLargestNode(node->getLeftChild());

            /*  Set the new data to the node  */
            node->setData(temp->getData());

            /*  Eliminate the node with the past value inside the left tree  */

            if (deleteNodeHelper(temp->getData(), node->getLeftChild()))
            {
                node->setLeftChild(nullptr);
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Private method that finds the smallest value Binary Tree node inside a Binary Tree.
 *
 * @tparam T Primitive types or classes.
 * @param node Root of the Binary Tree to search.
 * @return BinaryNode<T>*
 */
template <typename T>
BinaryNode<T> *BinaryTree<T>::findSmallestNode(BinaryNode<T> *node)
{
    /*  This could be implemented in a recursive form also, but I prefer
     in an iterative form because where are just moving in the left child*/
    while (node != nullptr && node->getLeftChild() != nullptr)
    {
        node = node->getLeftChild();
    }
    return node;
}

/**
 * @brief Private method that finds the largest value Binary Tree node inside a Binary Tree.
 *
 * @tparam T Primitive types or classes.
 * @param node Root of the Binary Tree to search.
 * @return BinaryNode<T>*
 */
template <typename T>
BinaryNode<T> *BinaryTree<T>::findLargestNode(BinaryNode<T> *node)
{
    /*  This could be implemented in a recursive form also, but I prefer
     in an iterative form because where are just moving in the right child*/
    while (node != nullptr && node->getRightChild() != nullptr)
    {
        node = node->getRightChild();
    }
    return node;

    /** Recursive form
     * if(node->getLeftChild() != nullptr){
     * findMinimalNode(node->getLeftChild());
     * }
     *
     * return node;
     *
     */
}

/**
 * @brief Private method that calculate the height of a Binary Tree.
 *
 * @tparam T Primitive types or classes.
 * @param node Root of the Binary Tree to calculate the height.
 * @return BinaryNode<T>*
 */
template <typename T>
int BinaryTree<T>::heightHelper(BinaryNode<T> *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = heightHelper(node->getLeftChild());
    int rightHeight = heightHelper(node->getRightChild());

    return 1 + max(leftHeight, rightHeight);
}

/**
 * @brief Private method thats search for a specified node in the Binary Tree.
 *
 * @tparam T Primitive types or classes.
 * @param data Value of the node to find.
 * @param node Root of the Binary Tree.
 * @return true If the node was founded.
 * @return false If the node doesn't exist on the Binary Tree.
 */
template <typename T>
bool BinaryTree<T>::findNodeHelper(const T &data, BinaryNode<T> *node)
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
        return findNodeHelper(data, node->getLeftChild());
    }
    else
    {
        return findNodeHelper(data, node->getRightChild());
    }
    return false;
}

/**
 * @brief Private method that copies every Binary Tree node of a Binary Tree to another one.
 *
 * @tparam T Primitive types or classes
 * @param node Root of the outcome Binary Tree.
 * @return BinaryNode<T>*
 */
template <typename T>
BinaryNode<T> *BinaryTree<T>::copyTree(BinaryNode<T> *node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }

    auto *newNode = new BinaryNode<T>(node->getData());
    newNode->setLeftChild(copyTree(node->getLeftChild()));
    newNode->setRightChild(copyTree(node->getRightChild()));

    return newNode;
}

/**
 * @brief Private method that compares every node of two Binary Trees.
 *
 * @tparam T Primitive types or classes
 * @param node1 Root of the first Binary Tree to compare.
 * @param node2 Root of the first Binary Tree to compare.
 * @return true If all Binary Tree nodes of both are the same.
 * @return false If one Binary Tree node of one of Trees is different.
 */
template <typename T>
bool BinaryTree<T>::equals(const BinaryNode<T> *node1, const BinaryNode<T> *node2) const
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
 * @brief Private method that tells if a Binary Tree is empty.
 *
 * @tparam T Primitive types or classes.
 * @param node Root of the Binary Tree.
 * @return true If the root is nullptr.
 * @return false If the root is different of nullptr.
 */
template <typename T>
bool BinaryTree<T>::emptyHelper(BinaryNode<T> *node)
{
    if (node == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Method that print a Binary Tree in a Pre-order way.
 *
 */
template <typename T>
void BinaryTree<T>::traversePreOrder()
{
    traversePreOrderHelper(root);
    cout << endl;
}

/**
 * @brief Method that print a Binary Tree in a Post-order way.
 *
 */
template <typename T>
void BinaryTree<T>::traversePostOrder()
{
    traversePostOrderHelper(root);
    cout << endl;
}

/**
 * @brief Method that gets a height of Binary Tree.
 *
 * @return int height of the Binary Tree.
 */
template <typename T>
int BinaryTree<T>::height()
{
    return heightHelper(root);
}

/**
 * @brief Method that gets the smallest value of a Binary Tree node inside a Binary Tree.
 *
 * @tparam T Primitive types or classes

 * @return T Smallest value.
 */
template <typename T>
T BinaryTree<T>::smallest()
{
    return T(findSmallestNode(root)->getData());
}

/**
 * @brief Method that gets the Largest value of a Binary Tree node inside a Binary Tree.
 *
 * @tparam T Primitive types or classes

 * @return T Largest value.
 */
template <typename T>
T BinaryTree<T>::largest()
{
    return T(findLargestNode(root)->getData());
}

/**
 * @brief Method thats tells if the Binary Tree is empty or not.
 *
 * @return true If the root of the Binary Tree is nullptr.
 * @return false If the root of the Binary Tree is different nullptr.
 */
template <typename T>
bool BinaryTree<T>::empty()
{
    return emptyHelper(root);
}

/**
 * @brief Overload of operator '=' to assign all Binary Tree nodes to another Binary Tree.
 *
 * @tparam T Primitive types or classes
 * @param otherTree Destination Binary Tree.
 * @return BinaryTree<T>& With all Binary Tree nodes from other.
 */
template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &otherTree)
{
    // Avoid self-assignment
    if (this == &otherTree)
    {
        return *this;
    }

    // Delete current tree and copy other tree
    deleteTree(root);
    root = copyTree(otherTree.root);

    return *this;
}

/*
    * When overloading, the "helpers functions" must be declared as const, in others words the declaration
    * of the function must end with a const, for example:

    * int heightHelper(BinaryNode *node) const;

*/

/**
 * @brief Overload of operator '==' to compare two Binary Tree. it will compare every single
 * Binary Tree node of both trees.
 *
 * @tparam T Primitive types or classes
 * @param otherTree Second Binary Tree to compare.
 * @return true If both Binary Trees have exactly the same Binary Tree nodes values and amount.
 * @return false If one of the Binary Tree nodes are different.
 */
template <typename T>
bool BinaryTree<T>::operator==(const BinaryTree<T> &otherTree) const
{

    return equals(root, otherTree.root);
}

/**
 * @brief Overload of operator '!=' to compare two Binary Tree. it will compare every single
 * Binary Tree node of both trees.
 *
 * @tparam T Primitive types or classes
 * @param otherTree Second Binary Tree to compare.
 * @return true If one of the Binary Tree nodes are different.
 * @return false If both Binary Trees have exactly the same Binary Tree nodes values and amount.
 */
template <typename T>
bool BinaryTree<T>::operator!=(const BinaryTree<T> &otherTree) const
{
    /**
     * Use the == overload to compare if the trees are different, it
     * will return true, if are equals return false.
     */
    return !(*this == otherTree);
}

/*
    The template T is being used in the context of the Binary Tree class, If we try to use T as a
    new template parameter in the << operator overload, will throw an error because it doesn't know
    which T we're referring to.

    It is necessary to use a new template parameter in the << operator overload, such as U, to avoid
    name conflicts with T.

    Also must be a friend operation, cannot be a class overload method.

*/

/**
 * @brief Overload of operator '<<' to print a Binary Tree. it will printed in a In-order way.
 *
 * @tparam U Primitive types or classes
 * @param os Output Stream
 * @param tree Binary Tree to be printed.
 * @return ostream& Output of the Binary Tree in a In-order way.
 */
template <typename U>
ostream &operator<<(ostream &os, const BinaryTree<U> &tree)
{
    tree.traverseInOrderHelper(tree.root, os);
    return os;
}

/**
 * @brief Overload of operator '<' to knows witch Binary Tree has a smaller height.
 *
 * @tparam T Primitive types or classes.
 * @param otherTree Second Binary Tree to compare.
 * @return true If the first Binary Tree has a smaller height than the second.
 * @return false If the second Binary Tree has a smaller height the first one.
 */
template <typename T>
bool BinaryTree<T>::operator<(const BinaryTree &otherTree) const
{
    return heightHelper(root) < heightHelper(otherTree.root);
}

/**
 * @brief Overload of operator '>' to knows witch Binary Tree has a larger height.
 *
 * @tparam T Primitive types or classes.
 * @param otherTree Second Binary Tree to compare.
 * @return true If the first Binary Tree has a larger height than the second.
 * @return false If the second Binary Tree has a larger height the first one.
 */
template <typename T>
bool BinaryTree<T>::operator>(const BinaryTree &otherTree) const
{
    return heightHelper(otherTree.root) > heightHelper(root);
}

/**
 * @brief Overload of operator '<=' to knows if a Binary Tree has an equal or
 * smaller height than the other one.
 *
 * @tparam T Primitive types or classes.
 * @param otherTree
 * @return true If the first Binary Tree has a smaller or equals height than the second.
 * @return false If the second Binary Tree has a smaller height than the first one.
 */
template <typename T>
bool BinaryTree<T>::operator<=(const BinaryTree &otherTree) const
{
    return !(heightHelper(otherTree.root) < heightHelper(root));
}

/**
 * @brief Overload of operator '>=' to knows if a Binary Tree has an equal or
 * larger height than the other one.
 *
 * @tparam T Primitive types or classes.
 * @param otherTree
 * @return true If the first Binary Tree has a larger or equal height than the second.
 * @return false If the second Binary Tree has a larger height than the first one.
 */
template <typename T>
bool BinaryTree<T>::operator>=(const BinaryTree &otherTree) const
{
    return !(heightHelper(root) < heightHelper(otherTree.root));
}
