#if !defined(DATA_STRUCTURES_QUAD_NODE_HPP)
#define DATA_STRUCTURES_QUAD_NODE_HPP

#include <array>

using namespace std;

class QuadNode
{
protected:
    double coordinateX, coordinateY;

    // 4 children, 0 = NW (North West), 1 = NE (North East), 2 = SW (South West), 3 = SE (South East)
    array<QuadNode *, 4> children;

public:
    /*  Constructors and Destructors  */
    QuadNode();

    QuadNode(const double &coordinateX, const double &coordinateY);

    QuadNode(const double &coordinateX, const double &coordinateY, const array<QuadNode *, 4> &children);

    ~QuadNode();

    /*  Getters and Setters  */
    double getCoordinateX();

    double getCoordinateY();

    array<QuadNode *, 4> getChildren();

    QuadNode *getChild(const int &index);

    void setCoordinateX(const double &coordinateX);

    void setCoordinateY(const double &coordinateY);

    void setChildren(const array<QuadNode *, 4> &children);

    void setChild(const int &index, QuadNode *child);
};

#include "../../../src/tree/quadTree/QuadNode.cpp"

#endif // DATA_STRUCTURES_QUAD_NODE_HPP
