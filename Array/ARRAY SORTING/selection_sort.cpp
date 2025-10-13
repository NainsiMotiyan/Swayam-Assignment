#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Loop over each element in the array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume current position is the minimum

        // Find the index of the smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if smaller element is found
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    selectionSort(arr);

    cout << "Sorted Array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
