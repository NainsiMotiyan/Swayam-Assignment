#include <iostream>
#include <vector>
using namespace std;

// Function to calculate running sum
vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();          // Get the size of the array
    vector<int> result(n);        // Create a new array to store running sums
    int sum = 0;                  // Variable to keep track of running sum

    // Loop through each element of nums
    for (int i = 0; i < n; i++) {
        sum += nums[i];           // Add current number to the running sum
        result[i] = sum;          // Store running sum in result array
    }

    return result;                // Return the final running sum array
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = runningSum(nums1);
    cout << "Test Case 1 Output: ";
    for (int num : result1) cout << num << " ";   // Print all elements
    cout << endl;                                 // New line

    // Test Case 2
    vector<int> nums2 = {1, 1, 1, 1, 1};
    vector<int> result2 = runningSum(nums2);
    cout << "Test Case 2 Output: ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {3, 1, 2, 10, 1};
    vector<int> result3 = runningSum(nums3);
    cout << "Test Case 3 Output: ";
    for (int num : result3) cout << num << " ";
    cout << endl;

    return 0;
}
