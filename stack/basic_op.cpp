#include <iostream>
using namespace std;

class stack {
public:
    int size;
    int top;
    int *s;

    stack(int size = 10) : size(size), top(-1) {
        s = new int[size];
    }

    ~stack() {
        delete[] s;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "stack overflow" << endl;
        } else {
            top++;
            s[top] = x;
        }
    }

    int pop() {
        int x = -1;
        if (top == -1) {
            cout << "stack underflow" << endl;
        } else {
            x = s[top--];
        }
        return x;
    }

    int peek(int index) {
        int x = -1;
        if (top - index + 1 < 0) {
            cout << "invalid index" << endl;
        } else {
            x = s[top - index + 1];
        }
        return x;
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == size - 1;
    }
};

int main() {
    int size;
    cout << "Enter size of the stack: ";
    cin >> size;

    stack s(size);
    int choice;
    int value, index;

    while (1) {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Is Full\n6. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            cout << "Popped value: " << s.pop() << endl;
            break;
        case 3:
            cout << "Enter index to peek: ";
            cin >> index;
            cout << "Value at index " << index << ": " << s.peek(index) << endl;
            break;
        case 4:
            cout << (s.is_empty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;
        case 5:
            cout << (s.is_full() ? "Stack is full" : "Stack is not full") << endl;
            break;
        case 6:
            s.display();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
