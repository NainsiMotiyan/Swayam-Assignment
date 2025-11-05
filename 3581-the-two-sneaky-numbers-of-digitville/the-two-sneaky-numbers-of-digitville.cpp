class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int m = nums.size(), n = m - 2, x = 0;
        for (int v : nums) x ^= v;
        for (int i = 0; i < n; i++) x ^= i;
        int mask = x & -x, a = 0, b = 0;
        for (int v : nums) {
            if (v & mask) a ^= v;
            else b ^= v;
        }
        for (int i = 0; i < n; i++) {
            if (i & mask) a ^= i;
            else b ^= i;
        }
        return {a, b};
    }
};
