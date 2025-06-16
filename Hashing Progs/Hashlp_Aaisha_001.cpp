#include <iostream>  //LINEAR PROBING
using namespace std;

int hashTab[5];

void table() {
    for (int i = 0; i < 5; i++) {
        hashTab[i] = -1; //this indicates empty slots
    }
}

void insert() {
    int value;
    cout << "Enter a value: ";
    cin >> value;
    int index = value % 5;

    if (hashTab[index] == -1) { // If slot is empty, place value
        hashTab[index] = value;
    } else {
        //Finding next available slot
        int startIndex = index; 
        while (hashTab[index] != -1) {
            index = (index + 1) % 5;
            if (index == startIndex) { // If table is full
                cout << "Hash table is full! Cannot insert " << value << endl;
                return;
            }
        }
        hashTab[index] = value;
    }
}

void display() {
    cout << "The hash table is:\n";
    for (int i = 0; i < 5; i++) {
        if (hashTab[i] == -1) {
            cout << "Index " << i << ": Empty\n";
        } else {
            cout << "Index " << i << ": " << hashTab[i] << "\n";
        }
    }
}

int main() {
    table();
    cout << "Enter any 5 values!\n";
    for (int i = 0; i < 5; i++) {
        insert();
    }

    display(); //final hash table
    return 0;
}

