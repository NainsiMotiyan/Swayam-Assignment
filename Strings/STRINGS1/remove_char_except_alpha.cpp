#include <iostream>
#include <cctype> // For isalpha()
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // Read full line including spaces

    string res = ""; // Result string to store only alphabets

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            res += s[i]; // Keep alphabet characters
        }
    }

    cout << "String with only alphabets: " << res << endl;

    return 0;
}
