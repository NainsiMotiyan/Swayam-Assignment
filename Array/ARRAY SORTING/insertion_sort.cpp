#include <iostream>
#include <vector>
using namespace std;

// Function to perform insertion sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Loop over each element starting from index 1
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // Current element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at the correct position
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    insertionSort(arr);

    cout << "Sorted Array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
