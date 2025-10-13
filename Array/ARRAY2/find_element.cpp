#include <iostream>
#include <vector>
using namespace std;

int findElement(vector<int>& nums, int target) {
    // Loop through the array
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found, return -1
}

int main() {
    vector<int> nums = {5, 3, 7, 1, 9, 2};
    int target;

    cout << "Enter the element to find: ";
    cin >> target;

    int index = findElement(nums, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}