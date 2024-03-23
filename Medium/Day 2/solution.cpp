// your code here
// CODE BY JAGPREET153
// This problem is based on Largest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;
int n,w[5001],h[5001],nex[5001],ans[5001],w1,h1;
int lsq(int item)   // It calculates the length of the largest increaing subsequence
{
    if(ans[item])  // If value has been calculated then return the value
    return ans[item];
    ans[item]=1;  // If value is not calculated then set it to 1

    for(int i=0;i<=n;i++)
    if(w[i]>w[item]&&h[i]>h[item])   // If the width and height of the current element is less than the next element then call the function recursively
    {
        if(lsq(i)+1>ans[item])
        {
            ans[item]=ans[i]+1;   // If the value of the subsequence is greater than the current value then update the value
            nex[item]=i;  // Updatation of next element of the subsequence is to be performed
        }
    }

    return ans[item];
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<=n;i++)
    {
        cin>>w[i]>>h[i];
        nex[i]=-1;   // It stores the next element of the subsequence
    }
    lsq(0);  
    cout<<ans[0]-1<<endl;
    for(i=nex[0];i!=-1;i=nex[i])  // It prints the subsequence
    cout<<i<<" ";
}