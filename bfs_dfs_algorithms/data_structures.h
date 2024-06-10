// data_structures.h
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>

// Structure for tree nodes
template <typename T>
struct Node
{
    T iPayload;
    Node *ptrLeft;
    Node *ptrRight;

    Node(T value) : iPayload(value), ptrLeft(nullptr), ptrRight(nullptr) {}
};

// Structure for list nodes
template <typename T>
struct ListNode
{
    T data;
    ListNode *next;

    ListNode(T value) : data(value), next(nullptr) {}
};

// Function prototypes
template <typename T>
Node<T> *insertNode(Node<T> *startingNode, T iData);

template <typename T>
Node<T> *searchDFS(Node<T> *startingNode, T iData);

template <typename T>
Node<T> *searchBFS(Node<T> *startingNode, T iData);

template <typename T>
void bfsTraversal(Node<T> *startingNode);

template <typename T>
int treeHeight(Node<T> *startingNode);

template <typename T>
void insertListNode(ListNode<T> *&head, T data);

template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args &&...args);

#endif // DATA_STRUCTURES_H
