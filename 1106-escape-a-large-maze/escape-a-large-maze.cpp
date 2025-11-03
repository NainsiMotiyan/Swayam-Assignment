#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int BOUND = 1000000;
    const int LIMIT = 20000;

    bool bfs(vector<int>& start, vector<int>& finish, unordered_set<long long>& blockedSet) {
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({start[0], start[1]});
        visited.insert({start[0], start[1]});
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == finish[0] && y == finish[1])
                return true;
            if (visited.size() > LIMIT)
                return true;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < BOUND && ny < BOUND) {
                    long long key = (long long)nx * BOUND + ny;
                    if (!blockedSet.count(key) && !visited.count({nx, ny})) {
                        visited.insert({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blockedSet;
        for (auto& b : blocked)
            blockedSet.insert((long long)b[0] * BOUND + b[1]);
        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }
};
