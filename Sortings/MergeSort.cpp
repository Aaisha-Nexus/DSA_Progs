#include<iostream>
using namespace std;

// Merging function
void merge(int arr[], int left, int mid, int right){
    int size1 = mid - left + 1;
    int size2 = right - mid;

    // Create temp arrays
    int a[size1], b[size2];

    // Copy data to temp arrays
    for(int i = 0; i < size1; i++)
        a[i] = arr[left + i];
    for(int j = 0; j < size2; j++)
        b[j] = arr[mid + 1 + j];

    // Merge the arrays
    int i = 0, j = 0, k = left;
    while(i < size1 && j < size2){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }

    // Copy remaining elements
    while(i < size1){
        arr[k++] = a[i++];
    }
    while(j < size2){
        arr[k++] = b[j++];
    }
}

// Merge sort function
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);        // Sort first half
        mergeSort(arr, mid + 1, right);   // Sort second half

        merge(arr, left, mid, right);     // Merge the sorted halves
    }
}

int main(){
    int arr[6] = {6, 3, 1, 5, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Merge Sort: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "After Merge Sort: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}