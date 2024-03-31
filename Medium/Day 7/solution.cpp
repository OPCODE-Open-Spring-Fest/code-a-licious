// your code here
// Code by Jagpreet153
// Approach solved using recursion and mathematical formulae
#include <bits/stdc++.h>
using namespace std;

long long calc(long long x, long long y) {
    long long t = 1;
    long long j = 1;
    while (j <= y) {
        t = t * x;
        j++;
    }
    return t;
}

long long ans(long long n, long long k) {
    if (n == 2) return k * (k - 1);
    return k * calc(k - 1, n - 1) - ans(n - 1, k);
}

long long result(long long n, long long k) {
    if (n == 1) return k;
    if ((k == 1) || ((n % 2 == 1) && (k == 2))) return -1;
    if ((k == 2) && (n % 2 == 0)) return 2;
    return ans(n, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << result(n, k) << endl;
    return 0;
}