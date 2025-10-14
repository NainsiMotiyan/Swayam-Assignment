#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>>& mat) {
    int maxRow = -1, maxCount = 0;
    for (int i = 0; i < mat.size(); i++) {
        int count = 0;
        for (int j = 0; j < mat[0].size(); j++)
            if (mat[i][j] == 1) count++;

        if (count > maxCount) {
            maxCount = count;
            maxRow = i;
        }
    }
    return maxRow;
}

int main() {
    vector<vector<int>> mat = {{0, 1, 1}, {1, 1, 1}, {0, 0, 1}};
    cout << "Row with maximum 1s: " << rowWithMax1s(mat) << endl;
    return 0;
}
