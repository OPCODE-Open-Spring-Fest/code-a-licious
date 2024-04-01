// Write your code here
// Code by Jagpreet153
// Approach : Brute Force
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n],cn=0,mi=0,sum=0,f=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]<0)
            {
                f=1;
                mi=min(mi,arr[i]);
            }
        }
        if(f==1)
        {
            sum=sum-mi;
        }
        else
        {
            sort(arr,arr+n);
            sum-=arr[0];
        }
        cout<<sum<<endl;


    }
}
