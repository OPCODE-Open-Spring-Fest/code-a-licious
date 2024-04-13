// Write your code here.
//Code by Jagpreet153
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
long long int  n, x ; 
cin >> n >> x;
  long long int  a[n + 1];
  for(long long int  i = 1; i <= n; i++) cin >> a[i];
  long long int  ans = 0;
  for(long long int  i = 2; i <= n; i++) {
    if(a[i - 1] + a[i] > x) {
        long long int  temp = a[i - 1] + a[i];
        temp = temp - x;
        ans += temp;
        if(temp > a[i]) a[i] = 0;
        else a[i] -= temp;
    }
  }
  cout << ans << endl;
  return 0;
}