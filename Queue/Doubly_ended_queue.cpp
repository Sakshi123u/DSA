#include<iostream>
using namespace std;

// Node class for a doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

// Doubly Ended Queue (Deque) class
class Deque {
private:
    Node* front; // Pointer to the front of the deque
    Node* rear;  // Pointer to the rear of the deque
    int size;    // Size of the deque

public:
    // Constructor
    Deque(){
        front=NULL;
        rear=NULL;
        size=0;
    }
    // Destructor
    ~Deque() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Method to insert an element at the front of the deque
    void enqueueFront(int x);

    // Method to insert an element at the rear of the deque
    void enqueueRear(int x);

    // Method to remove and return an element from the front of the deque
    int dequeueFront();

    // Method to display all elements in the deque
    void display();

    // Method to check if the deque is empty
    bool isEmpty() { return size == 0; }
};

// Method to insert an element at the front of the deque
void Deque::enqueueFront(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = front;

    if (isEmpty()) {
        rear = newNode;
    } else {
        front->prev = newNode;
    }

    front = newNode;
    size++;
}

// Method to insert an element at the rear of the deque
void Deque::enqueueRear(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = rear;

    if (isEmpty()) {
        front = newNode;
    } else {
        rear->next = newNode;
    }

    rear = newNode;
    size++;
}

// Method to remove and return an element from the front of the deque
int Deque::dequeueFront() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    Node* temp = front;
    int data = temp->data;
    front = front->next;

    if (front) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }

    delete temp;
    size--;
    return data;
}

// Method to display all elements in the deque
void Deque::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* temp = front;
    cout << "Displaying queue: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Testing the Deque class
    Deque q;
    q.enqueueRear(10);
    q.enqueueRear(20);
    q.enqueueRear(30);
    q.enqueueRear(40);
    q.enqueueRear(50);
    q.enqueueRear(60);
    q.display();

    q.dequeueFront();
    cout << "Displaying queue after dequeue from front: " << endl;
    q.display();

    q.enqueueFront(70);
    q.enqueueFront(80);
    cout << "Displaying queue after enqueue at front: " << endl;
    q.display();

    return 0;
}
