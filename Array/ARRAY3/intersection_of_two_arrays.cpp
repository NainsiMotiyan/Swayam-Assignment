#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Put all elements of nums1 into a set to remove duplicates
        unordered_set<int> set1(nums1.begin(), nums1.end());

        // Step 2: Use a set to store the intersection (unique elements only)
        unordered_set<int> result;

        // Step 3: Check each element of nums2
        for (int num : nums2) {
            if (set1.count(num)) { // If num is in set1
                result.insert(num); // Add to result set
            }
        }

        // Step 4: Convert the set to vector and return
        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> res = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : res) cout << num << " ";
    cout << endl; // Expected Output: 2

    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};

    vector<int> res2 = sol.intersection(nums3, nums4);

    cout << "Intersection: ";
    for (int num : res2) cout << num << " ";
    cout << endl; // Expected Output: 4 9 (order may vary)

    return 0;
}
