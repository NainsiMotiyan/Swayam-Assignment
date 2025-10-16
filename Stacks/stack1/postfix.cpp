#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char ch : exp) {
        // If operand -> push to stack
        if (isdigit(ch)) {
            st.push(ch - '0'); // convert char to int
        } else {
            // Pop top two operands
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            // Perform operation
            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    // Final result on top
    return st.top();
}

int main() {
    string exp = "231*+9-";
    cout << "Result: " << evaluatePostfix(exp);
    return 0;
}
