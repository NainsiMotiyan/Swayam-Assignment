#include <iostream>
#include <stack>
using namespace std;

// MinStack keeps track of the minimum element in O(1)
class MinStack {
    stack<int> st;       // normal stack
    stack<int> minSt;    // stack to track minimums
public:
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top())
            minSt.push(val); // update min
    }
    void pop() {
        if(st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    cout << "Min: " << ms.getMin() << endl; // 3
    ms.pop();
    cout << "Top: " << ms.top() << endl;    // 3
    cout << "Min: " << ms.getMin() << endl; // 3
}
