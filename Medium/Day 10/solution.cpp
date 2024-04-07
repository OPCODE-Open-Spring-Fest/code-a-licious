#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
	    long long int n;
	    cin >> n;
	    
	   long long  ans= (sqrt(1 + 8*n) - 1)/2;
	    cout << ans << endl;
	}
	return 0;
}
