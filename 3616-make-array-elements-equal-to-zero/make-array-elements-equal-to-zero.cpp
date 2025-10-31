#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeZero(vector<int> nums, int start, int dir) {
        int n = nums.size();
        int curr = start;
        int step = dir;

        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += step;
            } else {
                nums[curr]--;
                step = -step;
                curr += step;
            }
        }

        for (int x : nums) {
            if (x != 0) return false;
        }
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (canMakeZero(nums, i, 1)) count++;   
                if (canMakeZero(nums, i, -1)) count++;  
            }
        }
        return count;
    }
};
