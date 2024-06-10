// data_structures.cpp
#include "data_structures.h"
#include <chrono>
#include <queue>

using namespace std;
using namespace std::chrono;

// Function definitions

template <typename T>
Node<T> *insertNode(Node<T> *startingNode, T iData)
{
    if (startingNode == nullptr)
    {
        return new Node<T>(iData);
    }
    if (iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    return startingNode;
}

template <typename T>
Node<T> *searchDFS(Node<T> *startingNode, T iData)
{
    if (startingNode == nullptr || startingNode->iPayload == iData)
        return startingNode;
    if (iData < startingNode->iPayload)
        return searchDFS(startingNode->ptrLeft, iData);
    return searchDFS(startingNode->ptrRight, iData);
}

template <typename T>
Node<T> *searchBFS(Node<T> *startingNode, T iData)
{
    if (startingNode == nullptr)
        return nullptr;
    queue<Node<T> *> q;
    q.push(startingNode);
    while (!q.empty())
    {
        Node<T> *currentNode = q.front();
        q.pop();
        if (currentNode->iPayload == iData)
        {
            return currentNode;
        }
        if (currentNode->ptrLeft != nullptr)
        {
            q.push(currentNode->ptrLeft);
        }
        if (currentNode->ptrRight != nullptr)
        {
            q.push(currentNode->ptrRight);
        }
    }
    return nullptr;
}

template <typename T>
void bfsTraversal(Node<T> *startingNode)
{
    if (startingNode == nullptr)
        return;
    queue<Node<T> *> q;
    q.push(startingNode);
    while (!q.empty())
    {
        Node<T> *currentNode = q.front();
        q.pop();
        cout << currentNode->iPayload << " ";
        if (currentNode->ptrLeft != nullptr)
        {
            q.push(currentNode->ptrLeft);
        }
        if (currentNode->ptrRight != nullptr)
        {
            q.push(currentNode->ptrRight);
        }
    }
}

template <typename T>
int treeHeight(Node<T> *startingNode)
{
    if (startingNode == nullptr)
        return 0;
    int leftHeight = treeHeight(startingNode->ptrLeft);
    int rightHeight = treeHeight(startingNode->ptrRight);
    return max(leftHeight, rightHeight) + 1;
}

template <typename T>
void insertListNode(ListNode<T> *&head, T data)
{
    ListNode<T> *newNode = new ListNode<T>(data);
    newNode->next = head;
    head = newNode;
}

template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args &&...args)
{
    auto start = high_resolution_clock::now();
    func(forward<Args>(args)...);
    auto end = high_resolution_clock::now();
    duration<double, milli> execution_time = end - start;
    return execution_time.count();
}

// Explicit template instantiation
template Node<int> *insertNode(Node<int> *startingNode, int iData);
template Node<int> *searchDFS(Node<int> *startingNode, int iData);
template Node<int> *searchBFS(Node<int> *startingNode, int iData);
template void bfsTraversal(Node<int> *startingNode);
template int treeHeight(Node<int> *startingNode);
template void insertListNode(ListNode<int> *&head, int data);
template double measureExecutionTime<void (*)(Node<int> *), Node<int> *>(void (*func)(Node<int> *), Node<int> *&&);
template double measureExecutionTime<void (*)(ListNode<int> *&, int), ListNode<int> *&, int>(void (*func)(ListNode<int> *&, int), ListNode<int> *&, int &&);
template double measureExecutionTime<void (*)()>(void (*)());
