#include <iostream>
using namespace std;

// Recursive function to calculate sum of array
int arraySum(int arr[], int n) {
    if (n == 0) return 0;           // base case
    return arr[n - 1] + arraySum(arr, n - 1); // recursive case
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = arraySum(arr, n);
    cout << "Sum of array elements: " << sum << endl;

    return 0;
}
