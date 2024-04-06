// your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long int



void solve()
{ 
    
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        b[i] = 1LL*p*h;
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int i = 0;
    int cnt = 0;
    while (i < min(m, n))
    {
        cnt += min(a[i], b[i]);
        i++;
    }
    cout << cnt << endl;
}

signed main() 
{
	int t;
	cin>>t;
    // cout<<t<<endl;
	while(t--)
    {
        solve();   
    }
	return 0;
}

  