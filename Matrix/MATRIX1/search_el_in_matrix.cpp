#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m - 1;

    while (i < n && j >= 0) {
        if (mat[i][j] == target) return true;
        else if (mat[i][j] > target) j--;
        else i++;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    int target = 9;
    cout << (searchMatrix(mat, target) ? "Found" : "Not Found") << endl;
    return 0;
}
