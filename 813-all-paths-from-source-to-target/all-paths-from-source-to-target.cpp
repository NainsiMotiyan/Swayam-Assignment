#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            result.push_back(path);
        } else {
            for (auto next : graph[node]) {
                dfs(next, graph, path, result);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(0, graph, path, result);
        return result;
    }
};
