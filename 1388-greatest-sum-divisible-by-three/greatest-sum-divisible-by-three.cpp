class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int NEG = INT_MIN/2; 
        int dp[3] = {0, NEG, NEG};

        for (int x : nums) {
            int r = x % 3;
            int tmp[3] = {dp[0], dp[1], dp[2]}; 
            for (int old = 0; old < 3; ++old) {
                if (dp[old] <= NEG) continue; 
                int nw = (old + r) % 3;
                tmp[nw] = max(tmp[nw], dp[old] + x);
            }
            dp[0] = tmp[0]; dp[1] = tmp[1]; dp[2] = tmp[2];
        }
        return max(0, dp[0]); 
    }
};
