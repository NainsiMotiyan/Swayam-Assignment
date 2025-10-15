#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // Array to store stack elements
    int top;        // Index of the top element
    int capacity;   // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Push element onto stack
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // Pop element from stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Main function to test stack
int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}
