#include <iostream> 
using namespace std; 


struct Node {
    char data;
    Node* next;
};

Node* head = NULL;


// Ye function ek new node ko list ke end mein insert karta hai
void insert(char val) {
    Node* ptr = new Node(); // Naya node banaya
    ptr->data = val;        // Usmein value dali
    ptr->next = NULL;       // Abhi next kisi ko point nahi kar raha

    if (head == NULL) {     // Agar list empty hai to head ab new node ban jaye
        head = ptr;
    } else {
        Node* temp = head;
        // Jab tak list ka end na aa jaye tab tak aage badhte jao
        while (temp->next != NULL)
            temp = temp->next;
        // End pe new node attach kar do
        temp->next = ptr;
    }
}


// Ye function list ko reverse karta hai aur new head return karta hai
Node* reverse(Node* node) {
    Node* prev = NULL;
    Node* curr = node;
    Node* next = NULL;

    // Jab tak list khatam na ho
    while (curr != NULL) {
        next = curr->next;    // Agla node yaad rakhna
        curr->next = prev;    // Current ka next ko peechay walay pe point karwana
        prev = curr;          // Prev ko current bana dena
        curr = next;          // Aage badh jao
    }
    return prev; // New head (jo pehle last tha)
}


// Ye original list ka ek copy banata hai taake original ko reverse kar ke change na karein
Node* copyList(Node* node) {
    if (node == NULL) return NULL; // Agar list khali hai to NULL return

    Node* newHead = NULL;
    Node* tail = NULL;

    // Jab tak original list khatam na ho
    while (node != NULL) {
        Node* newNode = new Node(); // Naya node banao
        newNode->data = node->data; // Data copy karo
        newNode->next = NULL;

        if (newHead == NULL) {      // Agar pehla node hai
            newHead = tail = newNode;
        } else {
            tail->next = newNode;   // Last node ke next mein naya node attach karo
            tail = newNode;         // Tail ko update karo
        }
        node = node->next;          // Original list mein aage jao
    }

    return newHead; // Return karo copy list ka head
}


// Ye function check karta hai ke list palindrome hai ya nahi
bool isPalindrome() {
    Node* copy = copyList(head);      // Original ka copy banao
    Node* rev = reverse(copy);        // Copy ko reverse karo

    Node* temp1 = head;               // Original list ka pointer
    Node* temp2 = rev;                // Reversed list ka pointer

    // Dono lists ko ek sath compare karo
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) // Agar kisi bhi node ka data match nahi kara
            return false;              // To palindrome nahi hai
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true; // Agar sab match ho gaya to palindrome hai
}


// Ye function list ke saare elements ko display karta hai
void display(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}


int main() {
    char word[100]; // 100 characters tak ka word accept karne ke liye array
    cout << "Enter a word: ";
    cin >> word;    // User se word lena

    // Yeh loop har character ko linked list mein insert karega
    // '\0' ka matlab hota hai string ka end — jab tak null character na aa jaye, loop chalta rahega
    for (int i = 0; word[i] != '\0'; i++) {
        insert(word[i]); // Har character ko insert karo list mein
    }

    cout << "Original List: ";
    display(head); // Original list ko print karo

    cout << "Reversed List: ";
    display(reverse(copyList(head))); // Copy ko reverse karke print karo

    // Check karo ke palindrome hai ya nahi
    if (isPalindrome())
        cout << "It is a Palindrome " << endl;
    else
        cout << "Not a palindrome " << endl;

    return 0; // Program exit
}

