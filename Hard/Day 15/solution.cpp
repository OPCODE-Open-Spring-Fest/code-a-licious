// your code here
// Code by Jagpreet153
#include<bits/stdc++.h>
using namespace std;
const int maxn=3005,mod=1000000007;
int n,c,k,ans;
int f[maxn],C[maxn][maxn],inv[maxn],g[maxn][maxn][2],h[maxn][maxn];
void inc(int &x,int y){
	x+=y;
	if(x>=mod)
		x-=mod;
}
void dec(int &x,int y){
	x-=y;
	if(x<0)
		x+=mod;
}
int main(){
	cin>>n>>c>>k;
	g[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++){
			int v=g[i][j][0];
			inc(v,g[i][j][1]);
			inc(g[i+1][j][0],v),inc(g[i+1][j+1][1],v);
			if(i+c<=n)
				dec(g[i+c][j+c][1],g[i][j][0]);
		}
	for(int i=0;i<=n;i++){
		h[i][0]=(g[i][0][0]+g[i][0][1])%mod;
		for(int j=1;j<=n;j++){
			h[i][j]=(g[i][j][0]+g[i][j][1])%mod;
			inc(h[i][j],h[i][j-1]);
		}
    }
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1,inv[i]=i==1? 1:(mod-1ll*(mod/i)*inv[mod%i]%mod);
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int t=1;t<=n;t++)
		if(n%t==0){
			int lim=(c+k)/(n/t);
			for(int i=1;i<t&&i<=lim;i++){
				f[t]=(f[t]+C[t][i])%mod;
				f[t]=(f[t]-(g[t][i][0]+g[t][i][1])%mod+mod)%mod;
			}
			for(int i=1;i<c&&i<=t;i++)
				for(int j=c-i;j<c&&i+j<=t&&i+j<=lim;j++){
					if(i+j+1==t)
						inc(f[t],1);
					if(i+j+2<=t)
						inc(f[t],h[t-i-j-2][lim-i-j]);
				}
		}
	for(int i=1;i<=n;i++)
		for(int j=i+i;j<=n;j+=i)
			f[j]=(f[j]-f[i]+mod)%mod;
	for(int i=2;i<=n;i++)
		if(n%i==0){
			ans=(ans+1ll*f[i]*inv[i])%mod;
		}
	if(c+k>=n)
	inc(ans,1);
	cout<<ans;
	return 0;
}
