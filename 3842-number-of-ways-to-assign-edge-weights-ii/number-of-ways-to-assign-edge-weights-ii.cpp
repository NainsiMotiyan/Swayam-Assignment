class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;
    vector<long long> pow2;
    int LOG;

    void dfs(int node, int parent) {
        up[0][node] = parent;

        for (int child : adj[node]) {
            if (child == parent) continue;

            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i))
                u = up[i][u];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }

        return up[0][u];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        adj.resize(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n + 1));
        depth.assign(n + 1, 0);

        dfs(1, 1);

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                up[j][i] = up[j - 1][ up[j - 1][i] ];
            }
        }

        pow2.resize(n + 1);
        pow2[0] = 1;

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int L = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[L];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back((int)pow2[dist - 1]);
        }

        return ans;
    }
};