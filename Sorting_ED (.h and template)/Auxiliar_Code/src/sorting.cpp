#include "sorting.h"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void append(Node<T>** head, T iNewData) {
    Node<T>* newNode = new Node<T>(iNewData);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node<T>* last = *head;
    while (last->next != nullptr)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

template <typename T>
void bubbleSort(Node<T>* head) {
    bool bSwapped;
    do {
        bSwapped = false;
        Node<T>* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->iData > current->next->iData) {
                swap(current->iData, current->next->iData);
                bSwapped = true;
            }
            current = current->next;
        }
    } while (bSwapped);
}

template <typename T>
void optimizedBubbleSort(Node<T>* head) {
    bool bSwapped;
    Node<T>* pLast = nullptr;
    do {
        bSwapped = false;
        Node<T>* current = head;
        while (current->next != pLast) {
            if (current->iData > current->next->iData) {
                swap(current->iData, current->next->iData);
                bSwapped = true;
            }
            current = current->next;
        }
        pLast = current;
    } while (bSwapped);
}

template <typename T>
void selectionSort(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* min = current;
        Node<T>* r = current->next;
        while (r != nullptr) {
            if (r->iData < min->iData)
                min = r;
            r = r->next;
        }
        swap(current->iData, min->iData);
        current = current->next;
    }
}

template <typename T>
void optimizedSelectionSort(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* min = current;
        Node<T>* r = current->next;
        while (r != nullptr) {
            if (r->iData < min->iData)
                min = r;
            r = r->next;
        }
        if (min != current)
            swap(current->iData, min->iData);
        current = current->next;
    }
}

template <typename T>
void generateRandomList(Node<T>** head, int iSize) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < iSize; i++) {
        append(head, rand() % 10000); // Append random numbers between 0 and 9999
    }
}

template <typename T>
void freeList(Node<T>*& head) {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Explicit instantiations for the required types
template void swap<int>(int&, int&);
template void append<int>(Node<int>**, int);
template void bubbleSort<int>(Node<int>*);
template void optimizedBubbleSort<int>(Node<int>*);
template void selectionSort<int>(Node<int>*);
template void optimizedSelectionSort<int>(Node<int>*);
template void generateRandomList<int>(Node<int>**, int);
template void freeList<int>(Node<int>*&);
