#include <iostream> //DYNAMIC QUEUE IMPLEMENTATION (based on FIFO)
using namespace std;

struct Queue {
    int data;
    Queue* next;
};

Queue* front = NULL; //points to the first element 
Queue* rear = NULL; //points to the last element in queue

void enQueue() {
    Queue* ptr = new Queue();  
    int value;
    cout << "\nEnter the data in queue:\t";
    cin >> value;
	ptr->data=value;
    ptr->next = NULL; 

    // First insertion
    if (front == NULL) { //if front is null means queue is empty 
        front = ptr; //then front and rear points to the new node 
        rear = ptr;
    } else {
        rear->next = ptr; // otherwise  the new node is added at the rear and rear is updated 
        rear = ptr;
    }
}

void print() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Queue* temp = front;
    cout << "Queue elements:\n";
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

void deQueue() {
    if (front == NULL) { //check if the front is empty then no queue exist
        cout << "Queue is empty, nothing to delete!" << endl;
        return;
    }

    Queue* temp = front; // if front exists means there is a queue
    front = front->next; //update the front node 
    delete temp; //delete the tem/current front 
}

int main() {
    int size;
    char ans;
    cout << "Enter the size of the Queue:\t";
    cin >> size;

    for (int i = 0; i < size; i++) {
        enQueue();
        print();
    }



    cout << "Do you want to delete an element? (y/n): ";
    cin >> ans;
    if (ans == 'y' || ans == 'Y') {
        deQueue();
        print();
    }

    return 0;
}

