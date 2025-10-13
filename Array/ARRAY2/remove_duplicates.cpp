#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // Pointer to keep track of the position of the last unique element

        // Loop through the array with pointer j
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) { // If current element is different from last unique
                i++;                  // Move i to next position
                nums[i] = nums[j];    // Update the next unique element
            }
        }

        return i + 1; // The length of unique elements
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2};
    int len1 = sol.removeDuplicates(nums1);
    cout << "Test Case 1 Output Length: " << len1 << "\nArray: ";
    for (int i = 0; i < len1; i++) cout << nums1[i] << " ";
    cout << endl; // Expected: 2, Array: 1 2

    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    int len2 = sol.removeDuplicates(nums2);
    cout << "Test Case 2 Output Length: " << len2 << "\nArray: ";
    for (int i = 0; i < len2; i++) cout << nums2[i] << " ";
    cout << endl; // Expected: 5, Array: 0 1 2 3 4

    return 0;
}
