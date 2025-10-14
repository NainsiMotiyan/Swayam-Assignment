#include <iostream>
using namespace std;

// Function to print numbers from 1 to n using recursion
void printTillN(int n) {
    if (n == 0) return;       // base case

    printTillN(n - 1);        // recursive call for previous numbers
    cout << n << " ";         // print current number
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Numbers from 1 to " << n << ": ";
    printTillN(n);
    cout << endl;

    return 0;
}
