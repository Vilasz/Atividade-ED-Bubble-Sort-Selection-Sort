#include "include/sorting.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace std::chrono;

namespace util {
    template<typename Func>
    long long measureAndPrint(Func func, ofstream& file) {
        auto start = high_resolution_clock::now();
        func();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << fixed << setprecision(6) << duration.count() << "ns" << "\n";
        return duration.count();
    }
}

int main() {
    const int iListSize = 10000; // Adjust this size for different tests
    const int numTests = 100;

    ofstream outputFile("Output_Sorting");

    outputFile << "Algorithm // Test // Duration(ms)\n";

    for (int test = 1; test <= numTests; ++test) {
        outputFile << "Execution #" << test << endl;

        Node<int>* head = nullptr;

        generateRandomList(&head, iListSize);
        outputFile << "Bubble Sort: ";
        util::measureAndPrint([&]() { bubbleSort(head); }, outputFile);
        freeList(head);

        generateRandomList(&head, iListSize);
        outputFile << "Optimized Bubble Sort: ";
        util::measureAndPrint([&]() { optimizedBubbleSort(head); }, outputFile);
        freeList(head);

        generateRandomList(&head, iListSize);
        outputFile << "Selection Sort: ";
        util::measureAndPrint([&]() { selectionSort(head); }, outputFile);
        freeList(head);

        generateRandomList(&head, iListSize);
        outputFile << "Optimized Selection Sort: ";
        util::measureAndPrint([&]() { optimizedSelectionSort(head); }, outputFile);
        freeList(head);

        generateRandomList(&head, iListSize);
        outputFile << "Insertion Sort: ";
        util::measureAndPrint([&]() { insertionSort(head); }, outputFile);
        freeList(head);

        generateRandomList(&head, iListSize);
        outputFile << "Counting Sort: ";
        util::measureAndPrint([&]() { countingSort(head); }, outputFile);
        freeList(head);

        outputFile << endl;
    }

    outputFile << "Sorting tests completed." << endl;

    outputFile.close();
    return 0;
}
