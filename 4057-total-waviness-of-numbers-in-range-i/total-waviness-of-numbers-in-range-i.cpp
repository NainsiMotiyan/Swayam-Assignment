class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][2][3][11][11];
    bool vis[20][2][3][11][11];

    Node dfs(int pos, bool tight, bool started,
             int lenState, int last2, int last1) {
        
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][lenState][last2][last1]) {
            return dp[pos][started][lenState][last2][last1];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        Node ans{0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, ntight, false, 0, 10, 10);
                ans.cnt += child.cnt;
                ans.sum += child.sum;
                continue;
            }

            if (!started) {
                Node child = dfs(pos + 1, ntight, true, 1, 10, d);

                ans.cnt += child.cnt;
                ans.sum += child.sum;
            } else {
                long long add = 0;

                if (lenState >= 2) {
                    if ((last1 > last2 && last1 > d) ||
                        (last1 < last2 && last1 < d)) {
                        add = 1;
                    }
                }

                int nextLenState = min(2, lenState + 1);
                int nextLast2 = (lenState >= 1 ? last1 : 10);
                int nextLast1 = d;

                Node child = dfs(pos + 1, ntight, true,
                                 nextLenState, nextLast2, nextLast1);

                ans.cnt += child.cnt;
                ans.sum += child.sum + child.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][started][lenState][last2][last1] = true;
            dp[pos][started][lenState][last2][last1] = ans;
        }

        return ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, false, 0, 10, 10).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};