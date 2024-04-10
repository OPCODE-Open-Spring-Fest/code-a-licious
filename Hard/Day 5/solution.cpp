// your code here
#include <iostream>
using namespace std;

// Function to calculate nCr (combinations)
int nCr(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    }
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// Function to calculate the number of distinct distributions
int distinctDistributions(int N, int K) {
    return nCr(N / 2 + K - 1, K - 1);
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << distinctDistributions(N, K) << endl;

    return 0;
}
