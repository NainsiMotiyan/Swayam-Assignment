#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int ans = INT_MIN; // Store maximum product
        int p = 1;         // Prefix product
        int s = 1;         // Suffix product

        for (int i = 0; i < n; i++) {
            // Reset product to 1 if zero (start new subarray)
            p = (p == 0 ? 1 : p);
            s = (s == 0 ? 1 : s);

            p *= v[i];         // Multiply prefix
            s *= v[n - 1 - i]; // Multiply suffix

            ans = max(ans, max(p, s)); // Update overall maximum
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> v = {2, 3, -2, 4};

    int ans = sol.maxProduct(v);

    cout << "Maximum Product Subarray: " << ans << endl;

    return 0;
}
