#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the lower bound of a number in a sorted array
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) / 2;

        // if mid element >= target, move left
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int target = 4;
    cout << "Lower bound index: " << lowerBound(arr, target);
}
