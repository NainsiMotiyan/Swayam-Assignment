#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool canEat(vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int pile : piles)
        hours += ceil((double)pile / k);
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canEat(piles, h, mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed: " << minEatingSpeed(piles, h);
}
