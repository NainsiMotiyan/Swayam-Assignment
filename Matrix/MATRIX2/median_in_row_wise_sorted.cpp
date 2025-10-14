#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int medianMatrix(vector<vector<int>>& mat) {
    vector<int> temp;
    for (auto& row : mat)
        temp.insert(temp.end(), row.begin(), row.end());
    sort(temp.begin(), temp.end());
    return temp[temp.size() / 2];
}

int main() {
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << "Median: " << medianMatrix(mat) << endl;
    return 0;
}
