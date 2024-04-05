// Write your code here
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long int
// #define ff(n) for(int i=0;i<n;i++)
// #define pb push_back
// #define cy {cout<<"YES\n"; return;}
// #define cn {cout<<"NO"<<endl; return;}
// #define c0 {cout<<0<<endl; return;}
// #define c1 {cout<<1<<endl; return;}
// #define c01 {cout<<-1<<endl; return;}
// #define el {cout<<endl;}
// #define all(r) r.begin(),r.end()
// #define ffj(n) for(int j=0;j<n;j++)
// #define vp vector<pair <int,int>>
// #define mapp map<int,int> 
// #define vi vector<int>
// #define count int cnt=0;
// #define array {int n; cin>>n;int a[n];ff(n) cin>>a[i];}
// #define ipn {int n; cin>>n;}

// #define MOD 1000000007
// #define MAX 1000009

// int dp[MAX][2];
// void solve()
// { 
//      int n;
//     cin>>n;
//  int mod=1000000007;
//  int a[1000002]={0};
//  int i,s;
// s=0;
// a[0]=0;
// a[1]=1;
// a[2]=2;
// s=3;
// for(i=3;i<=n;i++)
// {
//  a[i]=(a[i]+a[i-1]+1)%mod;
//  s=(s+a[i])%mod;
//  a[i]=(a[i]+a[i-2])%mod;
// }
// if(n==1)
// cout<<1;
// else if(n==2)
// cout<<3;
// else
// cout<<s;
// 	// return 0;
// }


//     // int n;
// 	// cin>>n;
// 	// int t=1;
// 	// for(int i=1;i<=n;i++)
// 	// {
// 	// 	t=(t+1)%2;
// 	// 	for(int j=0;j<2;j++)
// 	// 	{
// 	// 		dp[i][j]=dp[i-1][j];
// 	// 		if(t==j)
// 	// 		{
// 	// 			dp[i][j]=(dp[i][j]+1+dp[i-1][(j+1)%2])%MOD;
// 	// 		}
// 	// 	}
// 	// }
// 	// cout<<(dp[n][0]+dp[n][1])%MOD<<endl;

// // }
        


// signed main() {
// 	// int t;
// 	// cin>>t;
//     // cout<<t<<endl;
// 	// while(t--)
//     // {
//         solve();   
//     // }
// 	return 0;
// }




// #include <iostream>
// using namespace std;
// long long int a[1000002]={0};
// int main() {
//     // cout<<5;
//     long long int n;
//     cin>>n;
//     long long int mod=1000000007;

//     long long int i,s;
//     s=0;
//     a[0]=0;
//     a[1]=1;
//     a[2]=2;
//     s=3;
//     for(i=3;i<=n;i++)
//     {
//         a[i]=(a[i]+a[i-1]+1)%mod;
//         s=(s+a[i])%mod;
//         a[i]=(a[i]+a[i-2])%mod;
//     }
//     if(n==1)
//     cout<<1;
//     else if(n==2)
//     cout<<3;
//     else
//     cout<<s;
//         return 0;
// }


/*
Problem Name: Teleporters Path
Problem Link: https://cses.fi/problemset/task/1693
Author: Sachin Srivastava (mrsac7)
*/


// #include <bits/stdc++.h>

// using namespace std;
// const int maxN = 1e5+1;

// bool vis[maxN];
// int N, M, in[maxN];
// vector<int> tour, G[maxN];
// stack<int> S;

// void dfs(int u = 1, int p = -1){
//     vis[u] = true;
//     for(int v : G[u])
//         if(v != p && !vis[v])
//             dfs(v, u);
// }

// int main(){
//     scanf("%d %d", &N, &M);
//     for(int i = 0, a, b; i < M; i++){
//         scanf("%d %d", &a, &b);
//         G[a].push_back(b);
//         in[b]++;
//     }

//     dfs();
//     bool exists = vis[N];
//     exists &= (in[1]+1 == (int) G[1].size());
//     exists &= (in[N]-1 == (int) G[N].size());
//     for(int i = 2; i < N; i++){
//         exists &= (in[i] == (int) G[i].size());
//         if(!vis[i]) exists &= (in[i] == 0 && G[i].size() == 0);
//     }

//     if(!exists){
//         printf("IMPOSSIBLE\n");
//         return 0;
//     }

//     S.push(1);
//     while(!S.empty()){
//         int u = S.top();
//         if(!G[u].empty()){
//             int v = G[u].back();
//             G[u].pop_back();
//             S.push(v);
//         } else {
//             tour.push_back(u);
//             S.pop();
//         }
//     }

//     reverse(tour.begin(), tour.end());
//     for(int i = 0; i < M+1; i++)
//         printf("%d%c", tour[i], (" \n")[i==M]);
// }




#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int SIZE = 8e5;

int N, Q, k, lo[SIZE], hi[SIZE], mp[SIZE];
ll x, sum[SIZE], dp[SIZE], dpl[SIZE], dpr[SIZE];

void pull(int i){
    dpl[i] = max(dpl[2*i], sum[2*i] + dpl[2*i+1]);
    dpr[i] = max(dpr[2*i+1], sum[2*i+1] + dpr[2*i]);
    dp[i] = max(dpr[2*i] + dpl[2*i+1], max(dp[2*i], dp[2*i+1]));
    sum[i] = sum[2*i] + sum[2*i+1];
}

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        scanf("%lld", &sum[i]);
        dpl[i] = dpr[i] = dp[i] = sum[i];
        mp[l] = i;
        return;
    }
    int m = l+(r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    pull(i);
}

void update(int a, ll b){
    a = mp[a];

    dpl[a] = dpr[a] = dp[a] = sum[a] = b;
    a >>= 1;
    while(a > 0){
        pull(a);
        a >>= 1;
    }
}

int main(){
    scanf("%d %d", &N, &Q);

    build(1, 1, N);
    for(int q = 0; q < Q; q++){
        scanf("%d %lld", &k, &x);
        update(k, x);
        printf("%lld\n", max(0LL, dp[1]));
    }
}
