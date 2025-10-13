#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; // size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array separated by spaces: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Find index of minimum element
    int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();

    // Find index of maximum element
    int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

    // Make sure minIndex < maxIndex for easier calculation
    if (minIndex > maxIndex) swap(minIndex, maxIndex);

    // Three possible ways to remove both:
    int deleteFromFront = maxIndex + 1;             // Remove both from the front
    int deleteFromBack = n - minIndex;             // Remove both from the back
    int deleteFromBothSides = (minIndex + 1) + (n - maxIndex); // One from front, one from back

    // Find the minimum deletions among the three options
    int minDeletions = min({deleteFromFront, deleteFromBack, deleteFromBothSides});

    cout << "Minimum number of deletions to remove min and max: " << minDeletions << endl;

    return 0;
}
