#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(vector<int>& stalls, int cows, int minDist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= minDist) {
            count++;
            last = stalls[i];
        }
    }
    return count >= cows;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls.front(), ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlace(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << "Largest minimum distance: " << aggressiveCows(stalls, cows);
}
