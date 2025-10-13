#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;  // Sum of all elements
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;   // Sum of elements to the left of current index

        for (int i = 0; i < nums.size(); i++) {
            // Right sum = totalSum - leftSum - nums[i]
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i; // Found the pivot index
            }
            leftSum += nums[i]; // Add current element to leftSum
        }

        return -1; // No pivot index found
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    cout << "Test Case 1 Pivot Index: " << sol.pivotIndex(nums1) << endl;
    // Expected Output: 3

    vector<int> nums2 = {1, 2, 3};
    cout << "Test Case 2 Pivot Index: " << sol.pivotIndex(nums2) << endl;
    // Expected Output: -1

    vector<int> nums3 = {2, 1, -1};
    cout << "Test Case 3 Pivot Index: " << sol.pivotIndex(nums3) << endl;
    // Expected Output: 0

    return 0;
}
