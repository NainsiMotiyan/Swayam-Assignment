#include <iostream>
#include <vector>
using namespace std;

void spiralTraversal(vector<vector<int>>& mat) {
    int top = 0, left = 0;
    int bottom = mat.size() - 1;
    int right = mat[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;

        // Traverse down
        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        // Traverse right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }

        // Traverse bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Spiral Traversal: ";
    spiralTraversal(mat);
    return 0;
}
