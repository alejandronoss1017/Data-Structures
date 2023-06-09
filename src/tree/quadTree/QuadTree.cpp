#include "../../../include/tree/quadTree/QuadTree.hpp"

QuadTree::QuadTree()
{

    QuadTree::root = nullptr;
    QuadTree::nodeCount = 0;
    QuadTree::pointCount = 0;
    QuadTree::maxPoints = 50;
    QuadTree::maxDepth = 50;
}

QuadTree::QuadTree(const double &coordinateX, const double &coordinateY)
{
    QuadTree::root = new QuadNode(coordinateX, coordinateY);
    QuadTree::nodeCount = 1;
    QuadTree::pointCount = 1;
    QuadTree::maxPoints = 50;
    QuadTree::maxDepth = 50;
}

QuadTree::~QuadTree() = default;

bool QuadTree::insert(const double &coordinateX, const double &coordinateY)
{
    if (root == nullptr)
    {
        root = new QuadNode(coordinateX, coordinateY);
        nodeCount++;
        pointCount++;
    }

    insertHelper(root, coordinateX, coordinateY);

    return true;
}

bool QuadTree::remove(const double &coordinateX, const double &coordinateY)
{
    if (root == nullptr)
    {
        return false;
    }

    removeHelper(root, coordinateX, coordinateY);

    return true;
}

bool QuadTree::find(const double &coordinateX, const double &coordinateY)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (findHelper(root, coordinateX, coordinateY) == nullptr)
    {
        return false;
    }

    return true;
}

bool QuadTree::empty()
{
    return false;
}

void QuadTree::clear()
{
    root = clearHelper(root);
    QuadTree::nodeCount = 0;
    QuadTree::pointCount = 0;
}

int QuadTree::height()
{
    if (root == nullptr)
    {
        return 0;
    }
    return QuadTree::nodeCount;
}

QuadNode *QuadTree::insertHelper(QuadNode *node, const double &coordinateX, const double &coordinateY)
{
    if (node == nullptr)
    {
        return new QuadNode(coordinateX, coordinateY);
        nodeCount++;
        pointCount++;
    }
    else
    {
        // If the point already exists, return the node
        if (coordinateX == node->getCoordinateX() && coordinateY == node->getCoordinateY())
        {
            return node;
        }
        else if (coordinateX < node->getCoordinateX())
        {
            if (coordinateY < node->getCoordinateY())
            {
                node->setChild(0, insertHelper(node->getChild(0), coordinateX, coordinateY));
            }
            else
            {
                node->setChild(1, insertHelper(node->getChild(1), coordinateX, coordinateY));
            }
        }
        else if (coordinateX > node->getCoordinateX())
        {
            if (coordinateY < node->getCoordinateY())
            {
                node->setChild(2, insertHelper(node->getChild(2), coordinateX, coordinateY));
            }
            else
            {
                node->setChild(3, insertHelper(node->getChild(3), coordinateX, coordinateY));
            }
        }
        // If coordinateX == node->getCoordinateX() && coordinateY != node->getCoordinateY()
        else
        {
            if (coordinateY < node->getCoordinateY())
            {
                node->setChild(0, insertHelper(node->getChild(0), coordinateX, coordinateY));
            }
            else
            {
                node->setChild(3, insertHelper(node->getChild(3), coordinateX, coordinateY));
            }
        }
    }
    return node;
}

QuadNode *QuadTree::removeHelper(QuadNode *node, const double &coordinateX, const double &coordinateY)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (coordinateX < node->getCoordinateX())
    {
        if (coordinateY < node->getCoordinateY())
        {
            node->setChild(0, removeHelper(node->getChild(0), coordinateX, coordinateY));
        }
        else
        {
            node->setChild(1, removeHelper(node->getChild(1), coordinateX, coordinateY));
        }
    }
    else if (coordinateX > node->getCoordinateX())
    {
        if (coordinateY < node->getCoordinateY())
        {
            node->setChild(2, removeHelper(node->getChild(2), coordinateX, coordinateY));
        }
        else
        {
            node->setChild(3, removeHelper(node->getChild(3), coordinateX, coordinateY));
        }
    }
    else
    {
        if (node->isLeaf())
        {
            delete node;
            node = nullptr;
            nodeCount--;
            pointCount--;
            return node;
        }
        else
        {
            QuadNode *temp = findMinHelper(node->getChild(3));
            node->setCoordinateX(temp->getCoordinateX());
            node->setCoordinateY(temp->getCoordinateY());
            node->setChild(3, removeHelper(node->getChild(3), temp->getCoordinateX(), temp->getCoordinateY()));
        }
    }
    return node;
}

QuadNode *QuadTree::findMinHelper(QuadNode *node)
{
    while (node != nullptr && node->getChild(0) != nullptr)
    {
        node = node->getChild(0);
    }
    return node;
}

QuadNode *QuadTree::findMaxHelper(QuadNode *node)
{
    while (node != nullptr && node->getChild(3) != nullptr)
    {
        node = node->getChild(3);
    }
    return node;
}

QuadNode *QuadTree::findHelper(QuadNode *node, const double &coordinateX, const double &coordinateY)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (coordinateX < node->getCoordinateX())
    {
        if (coordinateY < node->getCoordinateY())
        {
            return findHelper(node->getChild(0), coordinateX, coordinateY);
        }
        else
        {
            return findHelper(node->getChild(1), coordinateX, coordinateY);
        }
    }
    else if (coordinateX > node->getCoordinateX())
    {
        if (coordinateY < node->getCoordinateY())
        {
            return findHelper(node->getChild(2), coordinateX, coordinateY);
        }
        else
        {
            return findHelper(node->getChild(3), coordinateX, coordinateY);
        }
    }
    return node;
}

QuadNode *QuadTree::clearHelper(QuadNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    clearHelper(node->getChild(0));
    clearHelper(node->getChild(1));
    clearHelper(node->getChild(2));
    clearHelper(node->getChild(3));
    delete node;
    node = nullptr;
    return node;
}

void QuadTree::traverseInOrderHelper(QuadNode *node, ostream &os) const
{
    if (node == nullptr)
    {
        return;
    }
    traverseInOrderHelper(node->getChild(0), os);
    os << node->getCoordinateX() << " " << node->getCoordinateY() << endl;
    traverseInOrderHelper(node->getChild(1), os);
    traverseInOrderHelper(node->getChild(2), os);
    traverseInOrderHelper(node->getChild(3), os);
}

bool QuadTree::equals(const QuadNode *node1, const QuadNode *node2)
{
    return true;
}

ostream &operator<<(ostream &os, const QuadTree &tree)
{
    tree.traverseInOrderHelper(tree.root, os);
    return os;
}
