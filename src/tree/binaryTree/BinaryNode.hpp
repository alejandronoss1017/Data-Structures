#if !defined(DATA_STRUCTURES_BINARY_NODE_HPP)
#define DATA_STRUCTURES_BINARY_NODE_HPP

/**
 * @brief Template class for a Binary Tree Node.
 *

 * @tparam T Primitive types or classes.
 */
template <typename T>
class BinaryNode
{
protected:
    /*
      Because we are using pointers the syntax could change, also
      be careful with params types and returns type.

      Now we don't gonna use . instead use ->, also it's better
      to use nullptr over just null, it is used in pointer-based applications.
    */

    T data;
    BinaryNode<T> *rightChild;
    BinaryNode<T> *leftChild;

public:
    /*
      Constructor of the class is on public because,
      we need to create new nodes outside the BinaryNode class.
    */

    /* Constructors and Destructor */

    explicit BinaryNode(const T &data);

    ~BinaryNode();

    /*  Getters and Setters */

    T getData() const;

    void setData(const T &value);

    BinaryNode<T> *getLeftChild() const;

    void setLeftChild(BinaryNode<T> *node);

    BinaryNode<T> *getRightChild() const;

    void setRightChild(BinaryNode<T> *node);
};

#include "BinaryNode.cpp"

#endif // DATA_STRUCTURES_BINARY_NODE_HPP
