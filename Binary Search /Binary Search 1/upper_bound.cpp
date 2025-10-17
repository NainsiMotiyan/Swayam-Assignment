#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find upper bound index of target in sorted array
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int target = 4;
    cout << "Upper bound index: " << upperBound(arr, target);
}
