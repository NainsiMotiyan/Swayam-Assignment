#include <iostream>
using namespace std;

// Mock function (LeetCode provides this)
bool isBadVersion(int version) {
    return version >= 4; // Example: version 4 is first bad
}

int firstBadVersion(int n) {
    int low = 1, high = n, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main() {
    int n = 5;
    cout << "First bad version: " << firstBadVersion(n);
}
