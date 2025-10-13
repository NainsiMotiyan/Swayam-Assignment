#include <iostream>
#include <cctype> // For isalpha() and tolower()
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // Read full line including spaces

    int v = 0; // Count of vowels
    int c = 0; // Count of consonants
    int sp = 0; // Count of spaces

    for (int i = 0; i < s.size(); i++) {
        char ch = tolower(s[i]); // Convert to lowercase for easy comparison

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            v++; // Vowel found
        }
        else if (isalpha(ch)) {
            c++; // Consonant found
        }
        else if (ch == ' ') {
            sp++; // Space found
        }
    }

    cout << "Vowels: " << v << endl;
    cout << "Consonants: " << c << endl;
    cout << "Spaces: " << sp << endl;

    return 0;
}
