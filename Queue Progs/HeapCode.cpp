#include <iostream>
using namespace std;

const int MAX_SIZE = 100; //max elements are heap can hold
int heap[MAX_SIZE]; //  Global Array to hold heap elements
int heapSize = 0;   // Current number of elements in heap

// Swap two values manually
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ==============================
// Function to insert a new value in Max Heap
void insertMax(int value) {
    if (heapSize >= MAX_SIZE) {
        cout << "Heap is full!\n";
        return;
    }
    heap[heapSize] = value;      // Insert at end
    int index = heapSize; //store heapsize in index(current index) to compare later
    heapSize++;

    // Up-heapify (Max Heap logic: bubble up if (current) value > parent)
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) 
		{
            swap(heap[index], heap[parent]); //if child is greater than parent then swap cause in Maxheap parent is at top(since is greater)
            index = parent;
        } 
		else break;
    }
}

// ==============================
// Function to insert in Min Heap
void insertMin(int value) {
    if (heapSize >= MAX_SIZE) {
        cout << "Heap is full!\n";
        return;
    }
    heap[heapSize] = value;
    int index = heapSize;
    heapSize++;

    // Up-heapify (Min Heap logic: bubble up if value < parent)
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) { //if children is less than parent then swap cause in Minheap child is at top(since is greater)
            swap(heap[index], heap[parent]);
            index = parent;
        } else break;
    }
}

// ==============================
/* Down-Heapify for Max Heap  used in delete in Max heap
 heap = {50, 30, 40, 10, 20, 35}
Now let's delete the root 50:
Array: {35, 30, 40, 10, 20}

Now call downHeapifyMax(0)

index = 0, left = 1 (30), right = 2 (40)

Compare: heap[0]=35, heap[2]=40 -> 40 is largest

Swap 35 and 40
 New array: {40, 30, 35, 10, 20}

Continue with index = 2

Left = 5, right = 6 ? out of bounds

No more children ? done */
void downHeapifyMax(int index) {
    while (index < heapSize) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index; 
                                  //[replace the root node with largest child] 
        if (left < heapSize && heap[left] > heap[largest]) //[replace the root node with largest child] example heap(left) =30 > heap(largest)=35 X NO
            largest = left; 
        if (right < heapSize && heap[right] > heap[largest]) //example heap(right) =40 > heap(largest)=35 YES then make 40 largest
            largest = right; //largest=40

/* largest = 2; Right child
if (largest != index)  as 40 wasnt at the index[0] which it is supposed to be then swap and bring it there 
{
    swap(heap[0], heap[2]);  // 35 <--> 40
    index = 2;               // Now check index 2 and so on
}*/
        if (largest != index) 
		{
            swap(heap[index], heap[largest]);
            index = largest;
        } else break; //{40, 30, 35, 10, 20}
    }
}

// ==============================
// Down-Heapify for Min Heap used in Min heap deletion
/* Array: {10, 20, 15, 40, 50, 30}
Now delete root 10, replace with last ? heap[0] = 30
Array: {30, 20, 15, 40, 50}

Now call downHeapifyMin(0)

index = 0, left = 1 (20), right = 2 (15)

Compare: heap[0]=30, smallest among children = 15

Swap 30 and 15 ? Array: {15, 20, 30, 40, 50}

Now index = 2, left = 5, right = 6 ? out of bounds
Done.*/
void downHeapifyMin(int index) {
    while (index < heapSize) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heapSize && heap[left] < heap[smallest]) //replaces the root node with the smallest child 
            smallest = left;
        if (right < heapSize && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else break;
    }
}

// ==============================
// Delete root element in Max Heap
void deleteMax() {
    if (heapSize == 0) {
        cout << "Heap is empty!\n";
        return;
    }
    cout << "Deleting root: " << heap[0] << endl;
    heap[0] = heap[heapSize - 1]; // Replace root with last
    heapSize--;
    downHeapifyMax(0); // Restore heap property explanation above 
}

// ==============================
// Delete root in Min Heap
void deleteMin() {
    if (heapSize == 0) {
        cout << "Heap is empty!\n";
        return;
    }
    cout << "Deleting root: " << heap[0] << endl;
    heap[0] = heap[heapSize - 1];
    heapSize--;
    downHeapifyMin(0); //explnanation above 
}

// ==============================
// Print heap in array form
void printHeap() {
    cout << "Heap Array: ";
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

// ==============================
// Menu-driven program
int main() {
    int choice, value;
    cout << "===== HEAP PROGRAM (ARRAY IMPLEMENTATION) =====\n";

    do {
        cout << "\nMenu:\n";
        cout << "1) Insert (Max Heap)\n";
        cout << "2) Insert (Min Heap)\n";
        cout << "3) Delete Root (Max Heap)\n";
        cout << "4) Delete Root (Min Heap)\n";
        cout << "5) Print Heap\n";
        cout << "6) Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert in Max Heap: ";
                cin >> value;
                insertMax(value);
                break;

            case 2:
                cout << "Enter value to insert in Min Heap: ";
                cin >> value;
                insertMin(value);
                break;

            case 3:
                deleteMax();
                break;

            case 4:
                deleteMin();
                break;

            case 5:
                printHeap();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

