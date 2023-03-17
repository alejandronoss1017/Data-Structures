#include "../../../include/tree/avlTree/AVLTree.hpp"
#include "AVLTree.hpp"

template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(const T &data)
{
    // Fix constructor
    root = new AVLNode<T>(data);
}

template <typename T>
AVLTree<T>::~AVLTree() = default;

// Removed inline keyword and set highs
template <typename T>
AVLNode<T> *AVLTree<T>::insertHelper(const T &data, AVLNode<T> *node)
{

    // Si el nodo es nulo, creamos uno nuevo
    if (node == nullptr)
    {
        return new AVLNode<T>(data);
    }

    // Insertamos en el subárbol izquierdo
    if (data < node->getData())
    {
        node->setLeftChild(insertHelper(data, node->getLeftChild()));
    }
    // Insertamos en el subárbol derecho
    else if (data > node->getData())
    {
        node->setRightChild(insertHelper(data, node->getRightChild()));
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

    int prevSize = root->getHeight();
    root = insertHelper(data, root);
    int newSize = root->getHeight();
    return newSize > prevSize;
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
bool AVLTree<T>::remove(const T &data)
{
    return false;
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
bool AVLTree<T>::empty() const
{
    return emptyHelper(root);
}

template <typename U>
ostream &operator<<(ostream &os, const AVLTree<U> &tree)
{
    tree.traverseInOrderHelper(tree.root, os);
    return os;
}