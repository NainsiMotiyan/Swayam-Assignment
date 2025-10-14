#include <iostream>
#include <unordered_set>
using namespace std;

void removeDup(string &s, int idx, string &res, unordered_set<char> &seen) {
    if (idx == s.size()) return;
    if (seen.find(s[idx]) == seen.end()) {
        res += s[idx];
        seen.insert(s[idx]);
    }
    removeDup(s, idx + 1, res, seen);
}

int main() {
    string s, res = "";
    cout << "Enter a string: ";
    getline(cin, s);
    unordered_set<char> seen;
    removeDup(s, 0, res, seen);
    cout << "String after removing duplicates: " << res;
}
