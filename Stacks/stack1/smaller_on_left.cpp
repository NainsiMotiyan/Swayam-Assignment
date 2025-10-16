#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st; // stack to keep track of smaller elements

    for (int i = 0; i < n; i++) {
        // Remove all elements greater than or equal to current
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is empty -> no smaller element
        if (st.empty()) {
            result[i] = -1;
        } else {
            result[i] = st.top();
        }

        // Push current element into stack
        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 10, 5, 8, 20, 15, 3, 12};
    vector<int> ans = previousSmallerElement(arr);

    cout << "Previous smaller elements: ";
    for (int x : ans) cout << x << " ";
    return 0;
}
