#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findRepeatingElements(vector<int>& nums) {
    unordered_map<int, int> freq; // To store frequency of each element

    // Count frequency of each element
    for (int num : nums) {
        freq[num]++;
    }

    bool found = false;

    // Check which elements appear more than once
    for (auto it : freq) {
        if (it.second > 1) {
            cout << "Element " << it.first << " repeats " << it.second << " times" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No repeating elements found" << endl;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 4, 5, 1, 6};

    cout << "Array elements: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    findRepeatingElements(nums);

    return 0;
}
