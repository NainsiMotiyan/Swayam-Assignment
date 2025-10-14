#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Function to reverse the digits of a number
long long reverseNum(long long n) {
    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

// Function to compute (n^r) using modular exponentiation
long long power(long long n, long long r) {
    if (r == 0)
        return 1;
    long long half = power(n, r / 2);
    long long result = (half * half) % MOD;
    if (r % 2 != 0)
        result = (result * n) % MOD;
    return result;
}

int main() {
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    long long r = reverseNum(n);          // reverse of n
    long long ans = power(n, r) % MOD;    // compute n^r

    cout << "Result: " << ans << endl;
    return 0;
}
