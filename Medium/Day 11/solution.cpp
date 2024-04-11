// Write your code here
 #include<iostream>
#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0' || '9'<ch)ch=getchar();
    while('0'<=ch && ch<='9')x=x*10+(ch^48),ch=getchar();
    return x;
}

const int N=500009;

int n,k,ind[N];
int p[N],q[N];
set<int> f,b;
vector<int> g[N];

typedef set<int>::iterator it;

int main()
{
    n=read();
    k=read();

    for(int i=1;i<=n;i++)
        q[p[i]=read()]=i;
    for(int i=1;i<k;i++)
        f.insert(p[i]);
    for(int i=1;i<=n;i++)
    {
        if(i+k-1<=n)
            f.insert(p[i+k-1]);
        if(i)
            f.erase(p[i-1]);

        b.insert(p[i]);
        if(i>k)
            b.erase(p[i-k]);

        it cur=f.upper_bound(p[i]);
        if(cur!=f.end())
            g[q[*cur]].push_back(i),ind[i]++;
        cur=b.upper_bound(p[i]);
        if(cur!=b.end())
            g[q[*cur]].push_back(i),ind[i]++;
    }

    f.clear();
    for(int i=1;i<=n;i++)
        if(!ind[i])
            f.insert(-i);

    int top=0;
    while(f.size())
    {
        int u=-(*f.begin());
        p[++top]=u;
        f.erase(f.begin());
        for(int i=0,ed=g[u].size();i<ed;i++)
            if(--ind[g[u][i]]==0)
                f.insert(-g[u][i]);
    }

    for(int i=1;i<=n;i++)
        q[p[i]]=n-i+1;
    for(int i=1;i<=n;i++)
        printf("%d\n",q[i]);
    return 0;
}