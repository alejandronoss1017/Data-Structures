#include "include/tree/binaryTree/BinaryTree.hpp"
#include "include/tree/avlTree/AVLTree.hpp"
#include <iostream>

using namespace std;

int main()
{
    BinaryTree<int> myTree;
    AVLTree<int> myAVLTree;

    myAVLTree.insert(20);
    myAVLTree.insert(25);

    myAVLTree.insert(10);
    myAVLTree.insert(9);

    myAVLTree.insert(8);
    myAVLTree.insert(12);
    myAVLTree.insert(13);
    myAVLTree.insert(14);

    cout << myAVLTree << endl;

    // cout << myAVLTree.getRoot()->getData() << endl;

    // cout << "Is myTree empty? " << (myAVLTree.empty() ? "Yes" : "Nope") << endl;

    cout << "Is myTree empty? " << (myTree.empty() ? "Yes" : "Nope") << endl;

    for (int i = 50; i <= 100; i += 10)
    {
        myTree.insert(i);
    }

    for (int i = 40; i >= 0; i -= 10)
    {
        myTree.insert(i);
    }

    cout << "Traverse In-order: " << myTree << endl;

    cout << "Traverse Pre-order: ";
    myTree.traversePreOrder();

    cout << "Traverse Post-order: ";
    myTree.traversePostOrder();

    cout << "Is 100 in inside the tree? " << (myTree.find(100) ? "True" : "False") << endl;
    cout << "Is 200 in inside the tree? " << (myTree.find(200) ? "True" : "False") << endl;

    cout << "Tree height: " << myTree.height() << endl;

    cout << "Smallest value inside the tree: " << myTree.smallest() << endl;
    cout << "Largest value inside the tree: " << myTree.largest() << endl;

    BinaryTree<int> myTree2(80);

    myTree2 = myTree;

    cout << "Are those trees equals? " << ((myTree == myTree2) ? "Yeah!" : "Nope") << endl;

    cout << "Is 500 removed? " << (myTree2.remove(30) ? "Removed!" : "Can't removed") << endl;

    cout << myTree.height() << endl;

    myTree2.insert(900);
    myTree2.insert(12134);

    cout << myTree2.height() << endl;

    cout << "Are those trees stills equals? " << ((myTree == myTree2) ? "Yeah!" : "Nope") << endl;

    cout << "Is myTree equal or bigger than myTree2? " << ((myTree <= myTree2) ? "Yeah!" : "Nope") << endl;

    return 0;
}
