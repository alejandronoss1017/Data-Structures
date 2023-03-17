#include "../../../include/tree/avlTree/AVLTree.hpp"

/**
 * @brief Construct a new AVLTree with nullptr root.
 *
 * @tparam T Primitive types or classes.
 */
template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

/**
 * @brief Construct a new AVLTree with a root value.
 *
 * @tparam T Primitive types or classes.
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
 * @tparam T Primitive types or classes.
 */
template <typename T>
AVLTree<T>::~AVLTree()
{
    deleteTree(root);
}

/**
 * @brief Private method to create a new AVLNode and
 * insert it into the right position. Once the AVLNode is
 * inserted the AVLTree will update all nodes heights and
 * do balance.
 *
 * @tparam T Primitive types or classes.
 * @param node Root of the AVLTree to be inserted the new AVLNode.
 * @param data Value to be inserted inside the new AVLNode.
 * @return AVLNode<T>*
 */
template <typename T>
AVLNode<T> *AVLTree<T>::insertHelper(AVLNode<T> *node, const T &data)
{

    // Si el nodo es nulo, creamos uno nuevo
    if (node == nullptr)
    {
        return new AVLNode<T>(data);
    }

    // Insertamos en el subárbol izquierdo
    if (data < node->getData())
    {
        node->setLeftChild(insertHelper(node->getLeftChild(), data));
    }
    // Insertamos en el subárbol derecho
    else if (data > node->getData())
    {
        node->setRightChild(insertHelper(node->getRightChild(), data));
    }
    // Si el elemento ya existe, no hacemos nada
    else
    {
        return node;
    }

    // Actualizamos la altura del nodo actual
    updateHeight(node);

    // Balanceamos el árbol
    return balance(node);
}

template <typename T>
AVLNode<T> *AVLTree<T>::removeHelper(AVLNode<T> *node, const T &data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (data < node->getData())
    {
        node->setLeftChild(removeHelper(node->getLeftChild(), data));
    }
    else if (data > node->getData())
    {
        node->setRightChild(removeHelper(node->getRightChild(), data));
    }
    else
    {
        if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr)
        {
            delete node;
            node = nullptr;
            return node;
        }
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

template <typename T>
int AVLTree<T>::heightHelper(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    return node->getHeight();
}

template <typename T>
void AVLTree<T>::updateHeight(AVLNode<T> *node)
{
    int leftHeight = heightHelper(node->getLeftChild());
    int rightHeight = heightHelper(node->getRightChild());
    node->setHeight(max(leftHeight, rightHeight) + 1);
}

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
template <typename T>
bool AVLTree<T>::emptyHelper(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
void AVLTree<T>::deleteTree(AVLNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->getLeftChild());
    deleteTree(node->getRightChild());
    delete node;
}

template <typename T>
void AVLTree<T>::clearHelper(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        clearHelper(node->getLeftChild());
        clearHelper(node->getRightChild());
        delete node;
    }
}

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

template <typename T>
AVLNode<T> *AVLTree<T>::balance(AVLNode<T> *node)
{
    int bf = balanceFactor(node);

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

// Si la diferencia de altura difiere es igual 2 o -2 tenemos que rotar

// si es 2 el izquierdo el mas grande que el derecho, por lo que entramos al nodo izquierdo
// verificamos la altura de ese nodo, Diferencia entre alturas de hijos (izq - der) del hijo izquierdo
// Si diferencia > 0 → rotación a derecha
// Si diferencia < 0 → rotación izquierda-derecha

// si es -2 el derecho el mas grande que el izquierdo,

// es menor 0 revisamos el derecho (izquierda-derecha)
// Si la diferencia es mayor a 0 revisamos el izquierdo (izquierda-derecha)
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

template <typename T>
int AVLTree<T>::height() const
{
    if (root == nullptr)
    {
        return 0;
    }

    return root->getHeight();
}
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

template <typename T>
bool AVLTree<T>::operator==(const AVLTree<T> &otherTree) const
{
    return equals(root, otherTree.root);
}

template <typename T>
bool AVLTree<T>::operator!=(const AVLTree<T> &otherTree) const
{
    /**
     * Use the == overload to compare if the trees are different, it
     * will return true, if are equals return false.
     */
    return !(*this == otherTree);
}

template <typename T>
bool AVLTree<T>::operator<(const AVLTree &otherTree) const
{
    return root->getHeight() < otherTree.root->getHeight();
}

template <typename T>
bool AVLTree<T>::operator>(const AVLTree &otherTree) const
{
    return root->getHeight() > otherTree.root->getHeight();
}

template <typename T>
bool AVLTree<T>::operator<=(const AVLTree &otherTree) const
{
    return !(root->getHeight() < otherTree.root->getHeight());
}

template <typename T>
bool AVLTree<T>::operator>=(const AVLTree &otherTree) const
{
    return !(root->getHeight() > otherTree.root->getHeight());
}

template <typename T>
bool AVLTree<T>::remove(const T &data)
{
    int prevHeight = root->getHeight();
    root = removeHelper(root, data);
    int newHeight = root->getHeight();
    return newHeight < prevHeight;
}
template <typename T>
void AVLTree<T>::clear()
{
    clearHelper(root);
    root = nullptr;
}

template <typename T>
bool AVLTree<T>::find(const T &data) const
{
    if (findNodeHelper(root, data))
    {
        return true;
    }

    return false;
}
template <typename T>
void AVLTree<T>::traversePreOrder()
{
    traversePreOrderHelper(root);
}

template <typename T>
void AVLTree<T>::traversePostOrder()
{
    traversePostOrderHelper(root);
}

template <typename T>
bool AVLTree<T>::empty() const
{
    return emptyHelper(root);
}

template <typename T>
T AVLTree<T>::smallest() const
{
    return T(findSmallestNode(root)->getData());
}

template <typename T>
T AVLTree<T>::largest() const
{
    return T(findLargestNode(root)->getData());
}

template <typename U>
ostream &operator<<(ostream &os, const AVLTree<U> &tree)
{
    tree.traverseInOrderHelper(tree.root, os);
    return os;
}