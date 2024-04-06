// your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long int



void solve()
{ 
    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v(k);
    for(int i = 0; i < k; i++) cin >> v[i];
        int d = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]) d += 2;
            else d += 1;
        }
    for(int i: v)
    {
            if(s[i-1] == '0') s[i-1] = '1';
            else s[i-1] = '0';
            if(i-1 > 0){
                if(s[i-1] != s[i-2]) d--;
                else d++;
            }
            if(i-1 < n-1){
                if(s[i-1] != s[i]) d--;
                else d++;
            }
            cout << d << endl;
        
    }
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

  