// your code here
// Code by Jagpreet153
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll cnt=0;
       while(n%4==0) {
        n=n/4;
        cnt++;
       }
       cnt=(1<<cnt);
       ll k=sqrt(n);
       ll x=-1,y=-1;

       for(ll i=0;i<=k;i++) {
          ll temp=n-i*i;
          ld p = sqrt(temp);
          if(p==(ll)p) {
            x=i;
            y=p;
            break;
          }
       }
       if(x==-1)cout<<-1<<endl;
       else cout<<cnt*x<<" "<<cnt*y<<endl;
    }
    return 0;
}