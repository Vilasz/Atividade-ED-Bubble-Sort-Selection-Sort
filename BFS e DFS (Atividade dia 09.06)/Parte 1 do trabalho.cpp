// Parte 1 do Trabalho: Alterar para Lista Encadeada

#include <iostream>

using namespace std;

// Structure for tree nodes
typedef struct Node {
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

// Structure for queue nodes
typedef struct QueueNode {
    Node* treeNode;
    QueueNode* next;
} QueueNode;

// Structure for the queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);
Queue* createQueue();
void enqueue(Queue*, Node*);
Node* dequeue(Queue*);
bool isQueueEmpty(Queue*);
int treeHeight(Node*);

int main() {
    Node* root = nullptr;
    
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

Node* createNode(int iValue) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    
    if (tmp == nullptr) {
        cerr << "Error in createNode: malloc" << endl;
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

int treeHeight(Node* startingNode) {
    if (startingNode == nullptr) {
        return 0;
    }
    
    int leftHeight = treeHeight(startingNode->ptrLeft);
    int rightHeight = treeHeight(startingNode->ptrRight);
    
    return max(leftHeight, rightHeight) + 1;
}