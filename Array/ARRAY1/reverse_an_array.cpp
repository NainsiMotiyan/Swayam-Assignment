#include <iostream>
#include <vector>
#include <algorithm> // for reverse()
using namespace std;
using namespace std;

// Function to reverse the array after position M
void reverseArrayAfterM(vector<int>& arr, int m) {
    // We use the built-in reverse() function from STL
    // It will reverse all elements from (m+1) to the end of the array
    reverse(arr.begin() + m + 1, arr.end());
}

// Function to print the array
void printArray(const vector<int>& arr) {
    // Print each element separated by space
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl; // Move to the next line
}

// Main function - program starts here
int main() {
    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 5, 6}; // Our array
    int m1 = 3; // Position after which we reverse
    reverseArrayAfterM(arr1, m1); // Function call
    cout << "Test Case 1: ";
    printArray(arr1); // Expected Output: 1 2 3 4 6 5

    // Test Case 2
    vector<int> arr2 = {10, 20, 30, 40, 50};
    int m2 = 1; // Reverse part after index 1
    reverseArrayAfterM(arr2, m2);
    cout << "Test Case 2: ";
    printArray(arr2); // Expected Output: 10 20 50 40 30

    // Test Case 3
    vector<int> arr3 = {7, 9, 11, 13, 15, 17};
    int m3 = 0; // Reverse part after index 0
    reverseArrayAfterM(arr3, m3);
    cout << "Test Case 3: ";
    printArray(arr3); // Expected Output: 7 17 15 13 11 9

    // Test Case 4
    vector<int> arr4 = {4, 5, 6, 7, 8};
    int m4 = 4; // Last element, so nothing to reverse
    reverseArrayAfterM(arr4, m4);
    cout << "Test Case 4: ";
    printArray(arr4); // Expected Output: 4 5 6 7 8

    // Test Case 5
    vector<int> arr5 = {1, 2, 3, 4, 5};
    int m5 = 2; // Reverse part after index 2
    reverseArrayAfterM(arr5, m5);
    cout << "Test Case 5: ";
    printArray(arr5); // Expected Output: 1 2 3 5 4

    return 0; // End of program
}
