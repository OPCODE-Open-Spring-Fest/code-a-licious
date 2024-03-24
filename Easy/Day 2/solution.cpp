// Write your code here
#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}


long long mincal(int d,int n,long long cur,int pi,vector<int>& p)    
{
    if(d==n) return cur;
    long long res=(long long)2e18;
    for(int pow=1;;pow++) 
    {
        cur*=p[pi];
        if(d*(pow+1)>n || cur>res) break;
        res=min(res,mincal(d*(pow+1),n,cur,pi+1,p));
    }
    return res;
}
long long factorsum(int n)
{
    if(prime(n))
    {
        if(n>62) return LLONG_MAX;
        return (long long)pow(2,n-1);
    }
    vector<int> pr;
    int i=2;
    while(pr.size()<15)
    {
        if(prime(i)) pr.push_back(i);
        i++;
    }
    return mincal(1,n,1,0,pr);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    if(n==1) {cout << 1; return 0;}
    long long smallest=min(factorsum(2*n),factorsum(2*n-1));
    cout << smallest;
    
    return 0;
}
