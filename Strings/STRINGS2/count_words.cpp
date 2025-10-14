#include <iostream>
#include <sstream> // for stringstream
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    stringstream ss(s); // helps split words by spaces
    string word;
    int count = 0;

    // extract words one by one
    while (ss >> word) {
        count++;
    }

    cout << "\nNumber of words in the string: " << count << endl;
    return 0;
}
