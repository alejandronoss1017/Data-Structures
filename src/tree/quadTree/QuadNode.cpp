#include "../../../include/tree/quadTree/QuadNode.hpp"

QuadNode::QuadNode() = default;

QuadNode::QuadNode(const double &coordinateX, const double &coordinateY)
{
    QuadNode::coordinateX = coordinateX;
    QuadNode::coordinateY = coordinateY;
    QuadNode::children.fill(nullptr);
}

QuadNode::QuadNode(const double &coordinateX, const double &coordinateY, const array<QuadNode *, 4> &children)
{
    QuadNode::coordinateX = coordinateX;
    QuadNode::coordinateY = coordinateY;
    QuadNode::children = children;
}

QuadNode::~QuadNode() = default;

double QuadNode::getCoordinateX()
{
    return QuadNode::coordinateX;
}

double QuadNode::getCoordinateY()
{
    return QuadNode::coordinateY;
}

array<QuadNode *, 4> QuadNode::getChildren()
{
    return QuadNode::children;
}
QuadNode *QuadNode::getChild(const int &index)
{
    return QuadNode::children[index];
}

void QuadNode::setCoordinateX(const double &coordinateX)
{
    QuadNode::coordinateX = coordinateX;
}

void QuadNode::setCoordinateY(const double &coordinateX)
{
    QuadNode::coordinateY = coordinateY;
}

void QuadNode::setChildren(const array<QuadNode *, 4> &children)
{
    QuadNode::children = children;
}

void QuadNode::setChild(const int &index, QuadNode *child)
{
    QuadNode::children[index] = child;
}

bool QuadNode::isLeaf() const
{
    for (auto &&child : QuadNode::children)
    {
        if (child != nullptr)
        {
            return false;
        }
    }
    return true;
}