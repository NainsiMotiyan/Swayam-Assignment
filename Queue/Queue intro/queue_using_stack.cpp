#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;   // elements pushed here
    stack<int> outputStack;  // elements popped from here

public:
    // Constructor
    MyQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        inputStack.push(x);
    }

    // Removes the element from the front of queue and returns it
    int pop() {
        // Move elements if outputStack is empty
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }

    // Get the front element without removing it
    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }

    // Returns true if queue is empty
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

// Example usage
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // 1
    cout << "Removed: " << q.pop() << endl;        // 1
    cout << "Front element now: " << q.peek() << endl; // 2
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl;

    return 0;
}
