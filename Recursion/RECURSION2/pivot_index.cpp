#include <iostream>
using namespace std;

// Function to find total sum of array elements
int totalSum(int arr[], int n) {
    if (n == 0) return 0;                 // base case
    return arr[n - 1] + totalSum(arr, n - 1); // add last element + sum of rest
}

// Recursive function to find pivot index
int findPivot(int arr[], int n, int idx, int leftSum, int total) {
    if (idx == n) return -1;              // if reached end, no pivot found

    int rightSum = total - leftSum - arr[idx]; // right sum = total - left - current

    if (leftSum == rightSum) return idx;  // if both equal, pivot found

    // move to next index with updated left sum
    return findPivot(arr, n, idx + 1, leftSum + arr[idx], total);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i]; // input array

    int total = totalSum(arr, n);              // get total sum of array
    int pivot = findPivot(arr, n, 0, 0, total); // find pivot using recursion

    if (pivot != -1)
        cout << "Pivot index is: " << pivot << endl;
    else
        cout << "No pivot index found." << endl;

    return 0;
}
#include <iostream>
using namespace std;

// Function to find total sum of array elements
int totalSum(int arr[], int n) {
    if (n == 0) return 0;                 // base case
    return arr[n - 1] + totalSum(arr, n - 1); // add last element + sum of rest
}

// Recursive function to find pivot index
int findPivot(int arr[], int n, int idx, int leftSum, int total) {
    if (idx == n) return -1;              // if reached end, no pivot found

    int rightSum = total - leftSum - arr[idx]; // right sum = total - left - current

    if (leftSum == rightSum) return idx;  // if both equal, pivot found

    // move to next index with updated left sum
    return findPivot(arr, n, idx + 1, leftSum + arr[idx], total);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i]; // input array

    int total = totalSum(arr, n);              // get total sum of array
    int pivot = findPivot(arr, n, 0, 0, total); // find pivot using recursion

    if (pivot != -1)
        cout << "Pivot index is: " << pivot << endl;
    else
        cout << "No pivot index found." << endl;

    return 0;
}
