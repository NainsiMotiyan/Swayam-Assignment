class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        // Store indices for each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Process each group
        for (auto &it : mp) {
            vector<int> &v = it.second;
            int m = v.size();

            vector<long long> prefix(m, 0);
            prefix[0] = v[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = 1LL * i * v[i] - prefix[i - 1];
                }

                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - 
                            1LL * (m - i - 1) * v[i];
                }

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};