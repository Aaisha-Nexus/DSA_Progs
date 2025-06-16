// Priority Queue using Max Heap – Lab Task
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // heap max 100 elements rakh sakti hai
int heapSize = 0;         // Abhi heap mein kitne elements hain (start mein 0)

// Task structure 
struct Task {
    string name;   // Task ka naam
    int priority;  // Priority level
    int order;     // (jo pehle aaya usko preference)
};

Task heap[MAX_SIZE]; // Array of tasks, Max size 100

// Swap function – do tasks ki values ko exchange karta hai
void swap(Task &a, Task &b)  //pass by ref(original values mein change reflect ho)
{
    Task temp = a;
    a = b;
    b = temp;
}

// Ye check karta hai ke kaunsa task high priority wala hai
bool isHigherPriority(Task a, Task b) //here we just want to compare and modify nhi karna
 {
    if (a.priority != b.priority)
        return a.priority > b.priority; // Jiski priority zyada wo pehle
    else
        return a.order < b.order;       // Agar priority same ho to jo pehle aaya wo pehle (<) reperesents earlier "PEHLE AAO LEHLE PAO"
}

// Max Heap mein naya task insert karna
void insertMax(string taskName, int priority)
 {
    static int orderCounter = 0; // Har task ka unique order number maintain karta hai

    // Naya task create kar rahe hain
    Task t;
    t.name = taskName;
    t.priority = priority;
    t.order = orderCounter++; // Order assign kar diya for later processing if same priority 

    if (heapSize >= MAX_SIZE)
	 {
        cout << "Heap is full!\n";
        return;
    }

    // Task ko heap ke end par insert kar diya
    heap[heapSize] = t;
    int index = heapSize; // Abhi jis index par insert kiya usko yaad rakhein
    heapSize++;           // Heap ka size ek barh gaya

    // Up-Heapify – Jab naya task add karein to use sahi position tak upar le ke jao
    while (index > 0) 
	{
        int parent = (index - 1) / 2;

        // Agar child ki priority parent se zyada ho to swap karo
        if (heap[index].priority > heap[parent].priority) {
            swap(heap[index], heap[parent]);
            index = parent; // Ab new index parent ka ho gaya
        }
        // Agar priority same hai to order check karo
        else if (heap[index].priority == heap[parent].priority)
		 {
            if (heap[index].order < heap[parent].order) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else
			 {
                break; // Agar order bhi sahi hai to ruk jao
            }
        }
		 else 
		{
            break; // Agar priority choti ho to loop break
        }
    }
}

// Down-Heapify – Delete ke baad root ko sahi jagah tak neeche le jaata hai
void downHeapifyMax(int index)
 {
    while (index < heapSize) 
	{
        int left = 2 * index + 1;  // Left child
        int right = 2 * index + 2; // Right child
        int largest = index;       // Abhi assume karo yeh sabse bara hai (pehli value)

        // Left child check karo
        if (left < heapSize && isHigherPriority(heap[left], heap[largest]))
            largest = left;

        // Right child check karo
        if (right < heapSize && isHigherPriority(heap[right], heap[largest]))
            largest = right;

        // Agar koi child parent se bara nikla to swap karo
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest; // Neeche jaate raho jab tak max heap rule follow ho
        } else {
            break; // Sahi jagah aa gaya to ruk jao
        }
    }
}

// Max Heap se root (sabse high priority task) ko delete karna
void deleteMax() {
    if (heapSize == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    cout << "Deleting highest priority task: " << heap[0].name << " (Priority: " << heap[0].priority << ")\n";

    // Last element ko root par lao
    heap[0] = heap[heapSize - 1];
    heapSize--;

    // Heap ko restore karo
    downHeapifyMax(0);
}

void displayTasks() {
    if (heapSize == 0) {
        cout << "No tasks in the queue.\n";
        return;
    }

    cout << "\n?? Current Tasks by Priority (High ? Low):\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < heapSize; ++i) {
        cout << i + 1 << ". Task: " << heap[i].name 
             << " | Priority: " << heap[i].priority << endl;
    }
    cout << "------------------------------------------\n";
}

int main()
{
    while (true) {
        int choice;
        cout << "\n--- Task Priority Queue Menu ---\n";
        cout << "1. Add Task\n2. Remove Highest Priority Task\n3. Display All Tasks\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string task;
            int priority;
            cout << "Enter task name: ";
            cin >> task;
            cout << "Enter task priority: ";
            cin >> priority;
            insertMax(task, priority);
        } 
        else if (choice == 2) {
            deleteMax();
        } 
        else if (choice == 3) {
            displayTasks();
        } 
        else {
            cout << "Exiting...\n";
            break;
        }
    }

    return 0;
}

