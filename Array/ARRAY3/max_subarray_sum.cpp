#include <iostream>
#include <vector>
#include <algorithm> // for max
using namespace std;

// Function to find maximum subarray sum
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];   // Initialize maxSum with first element
    int currentSum = nums[0]; // Current subarray sum

    // Loop through the array starting from second element
    for (int i = 1; i < nums.size(); i++) {
        // Either extend the current subarray or start new from current element
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update maxSum if currentSum is greater
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums1) << endl;
    // Expected Output: 6 (subarray: [4, -1, 2, 1])

    vector<int> nums2 = {1};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums2) << endl;
    // Expected Output: 1

    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums3) << endl;
    // Expected Output: 23 (subarray: [5, 4, -1, 7, 8])

    return 0;
}
