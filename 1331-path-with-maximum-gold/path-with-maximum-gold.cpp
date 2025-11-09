#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m, ans = 0;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
        int gold = grid[i][j];
        grid[i][j] = 0;
        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);
        grid[i][j] = gold;
        return gold + max({up, down, left, right});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] != 0)
                    ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};
