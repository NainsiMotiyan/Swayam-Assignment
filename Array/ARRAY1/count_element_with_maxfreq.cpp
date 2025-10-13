#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();       // Get the size of the array
        int maxFreq = 0;           // To store the maximum frequency

        // Step 1: Find the maximum frequency of any element
        for (int i = 0; i < n; i++) {
            int count = 0;         // Count occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;       // Increment count if same element found
                }
            }
            if (count > maxFreq) {
                maxFreq = count;  // Update maximum frequency
            }
        }

        int total = 0;             // To store total elements with max frequency

        // Step 2: Count all elements that have the maximum frequency
        for (int i = 0; i < n; i++) {
            int count = 0;         // Count occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count == maxFreq) {        // If this element has max frequency
                total += count;           // Add its count to total

                // Step 3: Mark these elements so they are not counted again
                for (int j = 0; j < n; j++) {
                    if (nums[i] == nums[j]) {
                        nums[j] = -1e9;  // Use a number that doesn't exist in array
                    }
                }
            }
        }

        return total;                     // Return total count of max frequency elements
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    cout << "Test Case 1 Output: " << sol.maxFrequencyElements(nums1) << endl;
    // Expected Output: 3

    vector<int> nums2 = {4, 4, 4, 4};
    cout << "Test Case 2 Output: " << sol.maxFrequencyElements(nums2) << endl;
    // Expected Output: 4

    vector<int> nums3 = {1, 1, 2, 2, 3, 3};
    cout << "Test Case 3 Output: " << sol.maxFrequencyElements(nums3) << endl;
    // Expected Output: 6

    return 0;
}
