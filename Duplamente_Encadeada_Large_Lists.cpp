#include <iostream>
#include <chrono>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

struct Node {
    int iData;
    Node* next;
    Node* prev;
    Node(int data) : iData(data), next(nullptr), prev(nullptr) {}
};

void append(Node** head, int iNewData);
void printList(Node* head);
void bubbleSort(Node* head);
void optimizedBubbleSort(Node* head);
void selectionSort(Node* head);
void optimizedSelectionSort(Node* head);
void generateRandomList(Node** head, int iSize);

int main() {
    Node* head = nullptr;

    const int iListSize = 10000; // You can adjust this size for different tests
    generateRandomList(&head, iListSize);

    cout << "Starting sorting tests on a large list of size: " << iListSize << endl;

    auto start = high_resolution_clock::now();
    bubbleSort(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by Bubble Sort: " << duration.count() << " milliseconds" << endl;

    // Reset the list and test optimizedBubbleSort, selectionSort, and optimizedSelectionSort similarly
    delete head;
    head = nullptr;
    generateRandomList(&head, iListSize);

    start = high_resolution_clock::now();
    optimizedBubbleSort(head);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by Optimized Bubble Sort: " << duration.count() << " milliseconds" << endl;

    delete head;
    head = nullptr;
    generateRandomList(&head, iListSize);

    start = high_resolution_clock::now();
    selectionSort(head);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by Selection Sort: " << duration.count() << " milliseconds" << endl;

    delete head;
    head = nullptr;
    generateRandomList(&head, iListSize);

    start = high_resolution_clock::now();
    optimizedSelectionSort(head);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by Optimized Selection Sort: " << duration.count() << " milliseconds" << endl;

    return 0;
}

void append(Node** head, int iNewData) {
    Node* newNode = new Node(iNewData);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->iData << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(Node* head) {
    bool bSwapped;
    do {
        bSwapped = false;
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->iData > current->next->iData) {
                std::swap(current->iData, current->next->iData);
                bSwapped = true;
            }
            current = current->next;
        }
    } while (bSwapped);
}

void optimizedBubbleSort(Node* head) {
    bool bSwapped;
    Node* pLast = nullptr;
    do {
        bSwapped = false;
        Node* current = head;
        while (current->next != pLast) {
            if (current->iData > current->next->iData) {
                std::swap(current->iData, current->next->iData);
                bSwapped = true;
            }
            current = current->next;
        }
        pLast = current;
    } while (bSwapped);
}

void selectionSort(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* min = current;
        Node* r = current->next;
        while (r != nullptr) {
            if (r->iData < min->iData)
                min = r;
            r = r->next;
        }
        std::swap(current->iData, min->iData);
        current = current->next;
    }
}

void optimizedSelectionSort(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* min = current;
        Node* r = current->next;
        while (r != nullptr) {
            if (r->iData < min->iData)
                min = r;
            r = r->next;
        }
        if (min != current)
            std::swap(current->iData, min->iData);
        current = current->next;
    }
}


void generateRandomList(Node** head, int iSize) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < iSize; i++) {
        append(head, rand() % 10000); // Append random numbers between 0 and 9999
    }
}
