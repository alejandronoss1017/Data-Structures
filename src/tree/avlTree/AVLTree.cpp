#include "../../../include/tree/avlTree/AVLTree.hpp"

template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(const T &data)
{
    //Fix constructor
    root = new AVLNode<T>(data);
}

template <typename T>
AVLTree<T>::~AVLTree() = default;

//Removed inline keyword and set highs 
template <typename T>
bool AVLTree<T>::insertNode(const T &data, AVLNode<T> *node)
{
    // root->setHeight(heightHelper(root));
    if (data < node->getData())
    {
        if (node->getLeftChild() == nullptr)
        {
            node->setLeftChild(new AVLNode<T>(data));
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
            node->setRightChild(new AVLNode<T>(data));
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

template <typename T>
int AVLTree<T>::heightHelper(AVLNode<T> *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = heightHelper(node->getLeftChild());
    int rightHeight = heightHelper(node->getRightChild());

    return 1 + max(leftHeight, rightHeight);
}

template <typename T>
int AVLTree<T>::rebalance(AVLNode<T> *node) const
{
}

template <typename T>
AVLNode<T> *AVLTree<T>::rightRotation(AVLNode<T> *node)
{
    AVLNode<T> *parent = node->getLeftChild();
    node->setLeftChild(node->getRightChild());
    parent->setRightChild(node);

    node->setHeight(heightHelper(node));
    parent->setHeight(heightHelper(parent));

    return parent;
}

template <typename T>
AVLNode<T> *AVLTree<T>::leftRotation(AVLNode<T> *node)
{
    AVLNode<T> *parent = node->getRightChild();
    node->setRightChild(node->getLeftChild());
    parent->setLeftChild(node);

    node->setHeight(heightHelper(node));
    parent->setHeight(heightHelper(parent));
    return parent;
}

template <typename T>
AVLNode<T> *AVLTree<T>::rightLeftRotation(AVLNode<T> *node)
{
    node->setRightChild(rightRotation(node->getRightChild()));
    return leftRotation(node);
}
template <typename T>
AVLNode<T> *AVLTree<T>::leftRightRotation(AVLNode<T> *node)
{
    node->setLeftChild(leftRotation(node->getLeftChild()));
    return rightRotation(node);
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
    else
    {
        if (insertNode(data, root))
        {
            root->setHeight(heightHelper(root));
            int balance = heightHelper(root->getLeftChild()) - heightHelper(root->getRightChild());

            if (balance == 2)
            {

                int leftBalance = heightHelper(root->getLeftChild()->getLeftChild()) -
                                  heightHelper(root->getLeftChild()->getRightChild());

                if (leftBalance == 1 || leftBalance == 0)
                {
                    root = rightRotation(root);
                }
                else if (leftBalance == -1)
                {
                    leftRightRotation(root);
                }
            }
            else if (balance == -2)
            {
                int rightBalance = heightHelper(root->getRightChild()->getLeftChild()) -
                                   heightHelper(root->getRightChild()->getRightChild());
                if (rightBalance == -1 || rightBalance == 0)
                {
                    root = leftRotation(root);
                }
                else if (rightBalance == 1)
                {
                    rightLeftRotation(root);
                }
            }
            return true;
        }
    }
    return false;
}

template <typename T>
int AVLTree<T>::height()
{
    return heightHelper(root);
}

template <typename T>
bool AVLTree<T>::remove(const T &data)
{
    return false;
}

template <typename U>
ostream &operator<<(ostream &os, const AVLTree<U> &tree)
{
    tree.traverseInOrderHelper(tree.root, os);
    return os;
}