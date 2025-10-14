#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char aux, char dest) {
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        return;
    }
    // Move n-1 disks from src → aux
    towerOfHanoi(n - 1, src, dest, aux);
    // Move nth disk from src → dest
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    // Move n-1 disks from aux → dest
    towerOfHanoi(n - 1, aux, src, dest);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
}
