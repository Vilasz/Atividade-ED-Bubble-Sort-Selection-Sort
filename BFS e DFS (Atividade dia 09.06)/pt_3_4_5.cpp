// pt_3_4_5.cpp
#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "data_structures.h"

using namespace std;
using namespace std::chrono;

// Function definitions for measuring execution time
void measureInsertNode(Node<int> *&root, int val)
{
    root = insertNode(root, val);
}

void measureSearchDFS(Node<int> *root, int searchValue)
{
    searchDFS(root, searchValue);
}

void measureSearchBFS(Node<int> *root, int searchValue)
{
    searchBFS(root, searchValue);
}

void measureInsertListNode(ListNode<int> *&listHead, int val)
{
    insertListNode(listHead, val);
}

int main()
{
    const int NUM_ELEMENTS = 10000;
    vector<int> elements(NUM_ELEMENTS);
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        elements[i] = rand();
    }

    // Parte 5: Monitorar o desempenho de criação de árvores
    Node<int> *root = nullptr;
    double treeCreationTime = measureExecutionTime([&]()
                                                   {
        for (int val : elements) {
            measureInsertNode(root, val);
        } });
    cout << "Tempo de criação da árvore: " << treeCreationTime << " ms" << endl;

    // Parte 3: Monitorar o desempenho de busca em árvore utilizando DFS e BFS
    int searchValue = elements[NUM_ELEMENTS / 2];
    double dfsSearchTime = measureExecutionTime(measureSearchDFS, root, searchValue);
    cout << "Tempo de busca (DFS): " << dfsSearchTime << " ms" << endl;

    double bfsSearchTime = measureExecutionTime(measureSearchBFS, root, searchValue);
    cout << "Tempo de busca (BFS): " << bfsSearchTime << " ms" << endl;

    // Parte 4: Monitorar o desempenho de criação de listas
    ListNode<int> *listHead = nullptr;
    double listCreationTime = measureExecutionTime([&]()
                                                   {
        for (int val : elements) {
            measureInsertListNode(listHead, val);
        } });
    cout << "Tempo de criação da lista: " << listCreationTime << " ms" << endl;

    return 0;
}
