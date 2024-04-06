#include <bits/stdc++.h>
using namespace std;
#define int long long int



float sq(float n)
{
    float x = n;
    float y = 1;
 
    float e = 0.000001; 
    while (x - y > e)
    {
        x = (x + y) / 2;
        y = n/x;
    }
    return x;
}
 
int fun(int m)
{
    int n = 1 + 8*m;
    int mx = (-1 + sq(n)) / 2;
    return mx;
}

void solve()
{ 
    int k ;
    cin>>k;
    cout << fun(k) << endl;
    return ;
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

  