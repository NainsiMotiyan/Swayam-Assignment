class Solution {
public:

    class SparseTable {
    public:
        vector<vector<int>> mn, mx;
        int n, LOG;

        SparseTable(vector<int>& nums) {
            n = nums.size();
            LOG = 32 - __builtin_clz(n);

            mn.assign(LOG, vector<int>(n));
            mx.assign(LOG, vector<int>(n));

            for(int i = 0; i < n; i++) {
                mn[0][i] = nums[i];
                mx[0][i] = nums[i];
            }

            for(int k = 1; k < LOG; k++) {
                for(int i = 0; i + (1 << k) <= n; i++) {

                    mn[k][i] = min(
                        mn[k-1][i],
                        mn[k-1][i + (1 << (k-1))]
                    );

                    mx[k][i] = max(
                        mx[k-1][i],
                        mx[k-1][i + (1 << (k-1))]
                    );
                }
            }
        }

        int query(int L, int R) {

            int len = R - L;

            if(len <= 0) return 0;

            int k = 31 - __builtin_clz(len);

            int maximum = max(
                mx[k][L],
                mx[k][R - (1 << k)]
            );

            int minimum = min(
                mn[k][L],
                mn[k][R - (1 << k)]
            );

            return maximum - minimum;
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        SparseTable st(nums);

        priority_queue<
            vector<int>
        > pq;

        for(int i = 0; i < n; i++) {
            pq.push({st.query(i,n), i, n});
        }

        long long ans = 0;

        while(k-- && !pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int val = cur[0];
            int l   = cur[1];
            int r   = cur[2];

            if(val == 0) break;

            ans += val;

            if(r - 1 > l) {
                pq.push({
                    st.query(l,r-1),
                    l,
                    r-1
                });
            }
        }

        return ans;
    }
};