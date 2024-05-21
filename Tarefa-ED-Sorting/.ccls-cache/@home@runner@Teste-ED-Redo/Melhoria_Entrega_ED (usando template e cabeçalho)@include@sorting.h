#ifndef SORTING_H
#define SORTING_H

#include <iostream>

template <typename T>
struct Node {
    T iData;
    Node* next;
    Node* prev;
    Node(T data) : iData(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
void swap(T& a, T& b);

template <typename T>
void append(Node<T>** head, T iNewData);

template <typename T>
void bubbleSort(Node<T>* head);

template <typename T>
void optimizedBubbleSort(Node<T>* head);

template <typename T>
void selectionSort(Node<T>* head);

template <typename T>
void optimizedSelectionSort(Node<T>* head);

template <typename T>
void generateRandomList(Node<T>** head, int iSize);

template <typename T>
void freeList(Node<T>*& head);

#endif // SORTING_H
