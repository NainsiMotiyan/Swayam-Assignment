#include <iostream>
using namespace std;

// Function to count digits that divide n
int countDividingDigits(int n) {
    int count = 0;
    int temp = n; // copy of n for digit extraction

    while (temp > 0) {
        int digit = temp % 10; // get last digit
        temp /= 10;            // remove last digit

        // check conditions
        if (digit != 0 && n % digit == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = countDividingDigits(n);
    cout << "Count of digits that divide " << n << " evenly: " << result << endl;

    return 0;
}
