#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void swapValue(int &iX, int &iY) ;
void printArray(int iArr[], int iSize);
void bubbleSort(int iArr[], int iSize);
void optimizedBubbleSort(int iArr[], int iSize);
void selectionSort(int iArr[], int iSize);
void optimizedSelectionSort(int iArr[], int iSize);

int main() {
    int iNumbers[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iSize = sizeof(iNumbers) / sizeof(iNumbers[0]);

    cout << "Original array: ";
    printArray(iNumbers, iSize);

    auto timeStart = high_resolution_clock::now();
    bubbleSort(iNumbers, iSize);
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Sorted array (Bubble Sort): ";
    printArray(iNumbers, iSize);
    cout << "Time taken by function: " << timeDuration.count() << " nanoseconds" << endl;

   // Repetindo para optimized Bubble Sort
    int iNumbers4[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(iNumbers4, iSize);
    timeStop = high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Sorted array (Optimized Bubble Sort): ";
    printArray(iNumbers4, iSize);
    cout << "Time taken by function: " << timeDuration.count() << " nanoseconds" << endl;

    // Repetindo para Selection Sort
    int iNumbers2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    timeStart = high_resolution_clock::now();
    selectionSort(iNumbers2, iSize);
    timeStop = high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Sorted array (Selection Sort): ";
    printArray(iNumbers2, iSize);
    cout << "Time taken by function: " << timeDuration.count() << " nanoseconds" << endl;

    // Repetindo para Optimized Selection Sort
    int iNumbers3[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    timeStart = high_resolution_clock::now();
    optimizedSelectionSort(iNumbers3, iSize);
    timeStop = high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Sorted array (Optimized Selection Sort): ";
    printArray(iNumbers3, iSize);
    cout << "Time taken by function: " << timeDuration.count() << " nanoseconds" << endl;

    return 0;
}

void swapValue(int &iX, int &iY) {
    int iTemp = iX;
    iX = iY;
    iY = iTemp;
}

void printArray(int iArr[], int iSize) {
    for (int i = 0; i < iSize; i++)
        cout << iArr[i] << " ";
    cout << endl;
}

void bubbleSort(int iArr[], int iSize) {
    for (int i = 0; i < iSize - 1; i++) {
        for (int j = 0; j < iSize - 1; j++) {
            if (iArr[j] > iArr[j + 1])
                swapValue(iArr[j], iArr[j + 1]);
        }
    }
}

void optimizedBubbleSort(int iArr[], int iSize) {
    bool bSwapped;
    for (int i = 0; i < iSize - 1; i++) {
        bSwapped = false;
        for (int j = 0; j < iSize - 1 - i; j++) {
            if (iArr[j] > iArr[j + 1]) {
                swapValue(iArr[j], iArr[j + 1]);
                bSwapped = true;
            }
        }
        if (!bSwapped)
            break;
    }
}

void selectionSort(int iArr[], int iSize) {
    for (int i = 0; i < iSize - 1; i++) {
        int iMinIdx = i;
        for (int j = i + 1; j < iSize; j++)
            if (iArr[j] < iArr[iMinIdx])
                iMinIdx = j;
        swapValue(iArr[iMinIdx], iArr[i]);
    }
}

void optimizedSelectionSort(int iArr[], int iSize) {
    for (int i = 0; i < iSize - 1; i++) {
        int iMinIdx = i;
        for (int j = i + 1; j < iSize; j++)
            if (iArr[j] < iArr[iMinIdx])
                iMinIdx = j;
        if (iMinIdx != i)
            swapValue(iArr[iMinIdx], iArr[i]);
    }
}
