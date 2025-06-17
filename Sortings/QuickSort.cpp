#include <iostream>
using namespace std;

void QuickSort(int arr[], int L, int R) {
    int pivotI = (L + R) / 2;

    // Move elements from right towards pivot
    while (R > pivotI) {
        if (arr[pivotI] > arr[R]) {
            swap(arr[pivotI], arr[R]);
        }
        R--;
    }

    // Move elements from left towards pivot
    while (L < pivotI) {
        if (arr[pivotI] < arr[L]) {
            swap(arr[pivotI], arr[L]);
        }
        L++;
    }

    // Recursively sort left and right partitions
    if ((pivotI - 1) - L > 0) {
        QuickSort(arr, L, pivotI - 1);
    }

    if (R - (pivotI + 1) > 0) {
        QuickSort(arr, pivotI + 1, R);
    }
}

int main() {
    int arr[] = {83, 51, 12, 56, 46, 343};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Quick Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(arr, 0, size - 1);

    cout << "After Quick Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}