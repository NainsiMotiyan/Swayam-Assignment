#include <iostream>
#include <unordered_set> // to track seen characters
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    unordered_set<char> seen; // store characters already added
    string result = "";       // final string without duplicates

    for (char c : s) {
        if (seen.find(c) == seen.end()) { // if char not seen before
            result += c;                  // add to result
            seen.insert(c);               // mark as seen
        }
    }

    cout << "\nString after removing duplicates: " << result << endl;
    return 0;
}
