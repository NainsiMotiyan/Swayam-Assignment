#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> mat = {{5, 1, 9}, {3, 2, 8}, {7, 4, 6}};
    vector<int> temp;

    // Store all elements in one array
    for (auto row : mat)
        for (auto val : row)
            temp.push_back(val);

    // Sort all elements
    sort(temp.begin(), temp.end());

    cout << "Sorted Elements: ";
    for (int x : temp) cout << x << " ";
    return 0;
}
