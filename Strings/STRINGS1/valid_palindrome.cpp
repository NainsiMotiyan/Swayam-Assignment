#include <iostream>
#include <cctype> // For isalnum() and tolower()
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;             // Start pointer
        int j = s.size() - 1;  // End pointer

        while (i < j) {
            // Skip non-alphanumeric characters
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            // Compare characters (case-insensitive)
            if (tolower(s[i]) != tolower(s[j])) {
                cout << "Not a palindrome" << endl;
                return false;
            }

            i++;
            j--;
        }

        cout << "Is a palindrome" << endl;
        return true;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    getline(cin, s); // Read full line including spaces

    sol.isPalindrome(s);

    return 0;
}
