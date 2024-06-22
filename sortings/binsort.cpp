#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* first;
public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();
    void insert(Node*& bin, int x);
    int deleteA(Node*& bin);
    int findMax(int A[], int n);
    void binSort(int A[], int n);
};

// Constructor to create a linked list from an array
LinkedList::LinkedList(int A[], int n) {
    Node* last, * t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Destructor to delete the linked list
LinkedList::~LinkedList() {
    Node* p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

// Method to find the maximum element in an array
int LinkedList::findMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Method to insert elements into bins
void LinkedList::insert(Node*& bin, int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (bin == NULL) {
        bin = t;
    } else {
        Node* p = bin;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
    }
}

// Method to delete elements from bins and return the deleted element
int LinkedList::deleteA(Node*& bin) {
    Node* p = bin;
    bin = bin->next;
    int x = p->data;
    delete p;
    return x;
}

// Method to perform bin/bucket sort
void LinkedList::binSort(int A[], int n) {
    int max = findMax(A, n);

    // Create bins
    Node** bin = new Node * [max + 1];
    for (int i = 0; i <= max; i++) {
        bin[i] = NULL;
    }

    // Insert elements into their respective bins
    for (int i = 0; i < n; i++) {
        insert(bin[A[i]], A[i]);
    }

    // Collect elements from the bins and place them back into the array
    int i = 0, j = 0;
    while (i <= max) {
        while (bin[i] != NULL) {
            A[j++] = deleteA(bin[i]);
        }
        i++;
    }

    // Deallocate memory for bins
    delete[] bin;
}

// Main function to test bin/bucket sort
int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A) / sizeof(A[0]);

    LinkedList list;
    list.binSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
