#include <iostream>
#include <unordered_map> // for counting characters
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    unordered_map<char, int> freq; // stores char → frequency

    // count frequency of each character (excluding spaces)
    for (char c : s) {
        if (c != ' ') {
            freq[c]++;
        }
    }

    char maxChar = '\0'; // to store the max occurring character
    int maxCount = 0;    // to store the highest frequency

    // find character with maximum frequency
    for (auto ch : freq) {
        if (ch.second > maxCount) {
            maxCount = ch.second;
            maxChar = ch.first;
        }
    }

    cout << "\nCharacter with maximum occurrences: " << maxChar << endl;
    cout << "Number of occurrences: " << maxCount << endl;

    return 0;
}
