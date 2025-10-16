#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        // Push opening brackets
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            // If closing bracket but stack empty -> invalid
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Matching condition
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
                return false;
        }
    }

    // If stack empty -> all matched properly
    return st.empty();
}

int main() {
    string s = "{[()]}";
    if (isValid(s))
        cout << "Valid Parentheses";
    else
        cout << "Invalid Parentheses";
    return 0;
}
