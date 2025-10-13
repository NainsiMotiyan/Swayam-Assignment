#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k > n

        // Step 1: Reverse the whole array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    sol.rotate(nums1, k1);
    cout << "Test Case 1 Output: ";
    for (int num : nums1) cout << num << " ";
    cout << endl; // Expected: 5 6 7 1 2 3 4

    // Test Case 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    sol.rotate(nums2, k2);
    cout << "Test Case 2 Output: ";
    for (int num : nums2) cout << num << " ";
    cout << endl; // Expected: 3 99 -1 -100

    return 0;
}
