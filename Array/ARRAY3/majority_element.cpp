#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& v) {
        int c = 0;    // Counter for current candidate
        int el;       // Current candidate element

        // STEP 1: Find a potential majority candidate
        for (int i = 0; i < v.size(); i++) {
            if (c == 0) {
                el = v[i];  // Pick new candidate
                c = 1;
            } 
            else if (v[i] == el) {
                c++;        // Same as candidate, increase count
            } 
            else {
                c--;        // Different element, decrease count
            }
        }

        // STEP 2: Verify if candidate is really the majority
        int cnt = 0; 
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == el) {
                cnt++;     // Count occurrences of candidate
            }
        }

        // Return candidate if it occurs more than n/2 times
        if (cnt > v.size() / 2) {
            return el;
        }

        // No majority element exists
        return -1;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};

    int ans = sol.majorityElement(v);

    if (ans != -1)
        cout << "Majority Element: " << ans << endl;
    else
        cout << "No Majority Element exists." << endl;

    return 0;
}
