#include <iostream>
#include <vector>
using namespace std;

void rotate90(vector<vector<int>>& mat) {
    int n = mat.size();

    // Transpose matrix
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(mat[i][j], mat[j][i]);

    // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate90(mat);

    cout << "Matrix after 90° rotation:\n";
    for (auto row : mat) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
