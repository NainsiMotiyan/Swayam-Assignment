#include <iostream>
#include <vector>
using namespace std;

// Function to perform bubble sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    // Outer loop for number of passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if elements are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    bubbleSort(arr);

    cout << "Sorted Array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
