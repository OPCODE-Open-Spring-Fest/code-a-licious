#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[5];
ll dp[2][10];
void solve() {
    cin >> n >> a[0] >> a[1] >> a[2];
    dp[0][0] = 0;
    for (int i = 1; i < 8; i++) dp[0][i] = 4e18;
    for (int i = 1; i <= n; i++) {
        ll A;
        cin >> A;
        for (int j = 0; j < 8; j++) dp[i & 1][j] = 4e18;
        for (int j = 0; j < 8; j++) {
            ll l = 1;
            for (int k = 0; k < 3; k++) {
                if ((j >> k) & 1) {
                    l = l / __gcd(l, a[k]) * a[k];
                }
            }
            ll cnt = (l - (A % l))%l;
            for (int k = 0; k < 8; k++) {
                dp[i & 1][k | j] = min(dp[i & 1][k | j], dp[1 ^ i & 1][k] + cnt);
            }
        }
    }
    cout << dp[n & 1][7] << '\n';
}

int main() {
   solve();
    return 0;
}
