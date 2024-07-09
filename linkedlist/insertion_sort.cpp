#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL) {}
};

class Sol {
public:
    Node *head;
    Sol() : head(NULL) {}

    void create(int A[], int n) {
        if (n == 0) return;
        head = new Node(A[0]);
        Node *last = head;
        for (int i = 1; i < n; ++i) {
            Node *t = new Node(A[i]);
            last->next = t;
            last = t;
        }
    }

    Node* insertionSort(Node *head) {
        Node *dummy = new Node(0);  // dummy node for easier insertion
        Node *pre = dummy;
        Node *curr = head;
        Node *next = NULL;

        while (curr) {
            next = curr->next; // save the next node

            // Find the right place to insert the current node
            while (pre->next && pre->next->val < curr->val) {
                pre = pre->next;
            }

            // Insert the current node into the new list
            curr->next = pre->next;
            pre->next = curr;

            // Reset pre to the dummy node for the next iteration
            pre = dummy;
            curr = next; // move to the next node
        }

        Node *sortedHead = dummy->next;
        delete dummy; // free the dummy node
        return sortedHead;
    }

    void printList(Node *head) {
        Node *temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Sol s;
    int A[4] = {4, 1, 3, 2};
    s.create(A, 4);

    cout << "Original List: ";
    s.printList(s.head);

    s.head = s.insertionSort(s.head);

    cout << "Sorted List: ";
    s.printList(s.head);

    return 0;
}
