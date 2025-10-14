#include <iostream>
#include <unordered_map> // for storing character frequencies
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // read full string including spaces

    unordered_map<char, int> freq; // stores char → frequency

    // count frequency of each character
    for (char c : s) {
        if (c != ' ') { // ignore spaces
            freq[c]++;
        }
    }

    // display frequencies
    cout << "\nCharacter Frequencies:\n";
    for (auto ch : freq) {
        cout << ch.first << " → " << ch.second << endl;
    }

    return 0;
}
