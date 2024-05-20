#include "include/sorting.h"
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main() {
    const int iListSize = 10000; // You can adjust this size for different tests
    const int numTests = 100;
    
    cout << "Algorithm,Test,Duration(ms)\n";

    for (int test = 1; test <= numTests; ++test) {

        cout << "Execution #" << test << endl;

        
        Node<int>* head = nullptr;
        generateRandomList(&head, iListSize);

        auto start = high_resolution_clock::now();
        bubbleSort(head);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Bubble Sort:" << fixed << setprecision(6) << duration.count() << "ms" << "\n";
        freeList(head);

        generateRandomList(&head, iListSize);
        start = high_resolution_clock::now();
        optimizedBubbleSort(head);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Optimized Bubble Sort:" << fixed << setprecision(6) << duration.count() << "ms" << "\n";
        freeList(head);

        generateRandomList(&head, iListSize);
        start = high_resolution_clock::now();
        selectionSort(head);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Selection Sort:" << fixed << setprecision(6) << duration.count() << "ms" << "\n";
        freeList(head);

        generateRandomList(&head, iListSize);
        start = high_resolution_clock::now();
        optimizedSelectionSort(head);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Optimized Selection Sort:" << fixed << setprecision(6) << duration.count() << "ms" << "\n";
        freeList(head);

        cout << endl;
    }

    cout << "Sorting tests completed." << endl;

    return 0;
}
