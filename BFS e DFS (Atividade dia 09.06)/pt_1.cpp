// pt_1.cpp
#include <iostream>
#include "data_structures.h"

using namespace std;

int main()
{
    Node<int> *root = nullptr;

    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);

    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;

    cout << "Tree Height: " << treeHeight(root) << endl;

    return 0;
}
