// Parte 2 do Trabalho: Elaborar busca utilizando BFS (vocês já fizeram o DFS)

#include <iostream>

using namespace std;

// Estrutura para os nós da árvore
typedef struct Node {
    int iPayload;  // Valor armazenado no nó
    Node* ptrLeft;  // Ponteiro para o filho esquerdo
    Node* ptrRight; // Ponteiro para o filho direito
} Node;

// Estrutura para os nós da fila
typedef struct QueueNode {
    Node* treeNode;   // Nó da árvore armazenado na fila
    QueueNode* next;  // Próximo nó da fila
} QueueNode;

// Estrutura para a fila
typedef struct Queue {
    QueueNode* front; // Início da fila
    QueueNode* rear;  // Fim da fila
} Queue;

Node* createNode(int);
Node* insertNode(Node*, int);
Node* searchBFS(Node*, int);
Queue* createQueue();
void enqueue(Queue*, Node*);
Node* dequeue(Queue*);
bool isQueueEmpty(Queue*);
void bfsTraversal(Node*);
int treeHeight(Node*);

int main() {
    Node* root = nullptr;
    
    // Inserção de nós na árvore
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);
    
    // Traversal em BFS
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    // Altura da árvore
    cout << "Tree Height: " << treeHeight(root) << endl;
    
    // Busca em BFS
    int searchValue = 28;
    Node* searchResult = searchBFS(root, searchValue);
    if (searchResult) {
        cout << "Valor " << searchValue << " encontrado no nó com iPayload: " << searchResult->iPayload << endl;
    } else {
        cout << "Valor " << searchValue << " não encontrado na árvore." << endl;
    }
    
    return 0;
}

// Criação de um novo nó da árvore
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

// Inserção de um nó na árvore binária de busca
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

// Criação de uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = nullptr;
    return q;
}

// Inserção de um nó da árvore na fila
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

// Remoção de um nó da fila
Node* dequeue(Queue* q) {
    if (q->front == nullptr) return nullptr;
    
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    
    if (q->front == nullptr) q->rear = nullptr;
    
    free(temp);
    return treeNode;
}

// Verificação se a fila está vazia
bool isQueueEmpty(Queue* q) {
    return (q->front == nullptr);
}

// Traversal em BFS
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

// Busca em BFS
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

// Cálculo da altura da árvore
int treeHeight(Node* startingNode) {
    if (startingNode == nullptr) {
        return 0;
    }
    
    int leftHeight = treeHeight(startingNode->ptrLeft);
    int rightHeight = treeHeight(startingNode->ptrRight);
    
    return max(leftHeight, rightHeight) + 1;
}