// Parte 3 do Trabalho: Monitorar o desempenho de busca em árvore utilizando DFS e BFS
// Parte 4 do Trabalho: Monitorar o desempenho de criação de listas
// Parte 5 do Trabalho: Monitorar o desempenho de criação de árvores

#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
using namespace std::chrono;

typedef struct Node {
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

typedef struct ListNode {
    int data;
    ListNode* next;
} ListNode;

typedef struct QueueNode {
    Node* treeNode;
    QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Funções da árvore
Node* createNode(int);
Node* insertNode(Node*, int);
Node* searchDFS(Node*, int);
Node* searchBFS(Node*, int);
int treeHeight(Node*);
void bfsTraversal(Node*);
Queue* createQueue();
void enqueue(Queue*, Node*);
Node* dequeue(Queue*);
bool isQueueEmpty(Queue*);

// Funções da lista
ListNode* createListNode(int);
void insertListNode(ListNode*&, int);

// Função para medir o tempo de execução
template<typename Func, typename... Args>
double measureExecutionTime(Func func, Args&&... args);

int main() {
    const int NUM_ELEMENTS = 10000;
    vector<int> elements(NUM_ELEMENTS);
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        elements[i] = rand();
    }

    // Parte 5: Monitorar o desempenho de criação de árvores
    Node* root = nullptr;
    double treeCreationTime = measureExecutionTime([&]() {
        for (int val : elements) {
            root = insertNode(root, val);
        }
    });
    cout << "Tempo de criação da árvore: " << treeCreationTime << " ms" << endl;

    // Parte 3: Monitorar o desempenho de busca em árvore utilizando DFS e BFS
    int searchValue = elements[NUM_ELEMENTS / 2];
    double dfsSearchTime = measureExecutionTime(searchDFS, root, searchValue);
    cout << "Tempo de busca (DFS): " << dfsSearchTime << " ms" << endl;

    double bfsSearchTime = measureExecutionTime(searchBFS, root, searchValue);
    cout << "Tempo de busca (BFS): " << bfsSearchTime << " ms" << endl;

    // Parte 4: Monitorar o desempenho de criação de listas
    ListNode* listHead = nullptr;
    double listCreationTime = measureExecutionTime([&]() {
        for (int val : elements) {
            insertListNode(listHead, val);
        }
    });
    cout << "Tempo de criação da lista: " << listCreationTime << " ms" << endl;

    return 0;
}

Node* createNode(int iValue) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    if (tmp == nullptr) {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    return tmp;
}

Node* insertNode(Node* startingNode, int iData) {
    if (startingNode == nullptr) {
        return createNode(iData);
    }
    if (iData < startingNode->iPayload) {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    } else {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    return startingNode;
}

Node* searchDFS(Node* startingNode, int iData) {
    if (startingNode == nullptr || startingNode->iPayload == iData) return startingNode;
    if (iData < startingNode->iPayload) return searchDFS(startingNode->ptrLeft, iData);
    return searchDFS(startingNode->ptrRight, iData);
}

Node* searchBFS(Node* startingNode, int iData) {
    if (startingNode == nullptr) return nullptr;
    Queue* q = createQueue();
    enqueue(q, startingNode);
    while (!isQueueEmpty(q)) {
        Node* currentNode = dequeue(q);
        if (currentNode->iPayload == iData) {
            free(q);
            return currentNode;
        }
        if (currentNode->ptrLeft != nullptr) {
            enqueue(q, currentNode->ptrLeft);
        }
        if (currentNode->ptrRight != nullptr) {
            enqueue(q, currentNode->ptrRight);
        }
    }
    free(q);
    return nullptr;
}

void bfsTraversal(Node* startingNode) {
    if (startingNode == nullptr) return;
    Queue* q = createQueue();
    enqueue(q, startingNode);
    while (!isQueueEmpty(q)) {
        Node* currentNode = dequeue(q);
        cout << currentNode->iPayload << " ";
        if (currentNode->ptrLeft != nullptr) {
            enqueue(q, currentNode->ptrLeft);
        }
        if (currentNode->ptrRight != nullptr) {
            enqueue(q, currentNode->ptrRight);
        }
    }
    free(q);
}

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = nullptr;
    return q;
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = nullptr;
    if (q->rear == nullptr) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

Node* dequeue(Queue* q) {
    if (q->front == nullptr) return nullptr;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == nullptr) q->rear = nullptr;
    free(temp);
    return treeNode;
}

bool isQueueEmpty(Queue* q) {
    return (q->front == nullptr);
}

ListNode* createListNode(int data) {
    ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertListNode(ListNode*& head, int data) {
    ListNode* newNode = createListNode(data);
    newNode->next = head;
    head = newNode;
}

int treeHeight(Node* startingNode) {
    if (startingNode == nullptr) return 0;
    int iLeftHeight = treeHeight(startingNode->ptrLeft);
    int iRightHeight = treeHeight(startingNode->ptrRight);
    return max(iLeftHeight, iRightHeight) + 1;
}

template<typename Func, typename... Args>
double measureExecutionTime(Func func, Args&&... args) {
    auto start = high_resolution_clock::now();
    func(forward<Args>(args)...);
    auto end = high_resolution_clock::now();
    duration<double, milli> execution_time = end - start;
    return execution_time.count();
}