// Write your code here.
// Code By Jagpreet153
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200010],b[200010],c[200010];
set<int> ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		int x=a[i]^b[1],flg=1;
		for(int j=1;j<=n;j++) c[j]=x^a[j];
		sort(c+1,c+n+1);
		for(int j=1;j<=n;j++) if(c[j]!=b[j]) flg=0;
		if(flg) ans.insert(x);
	}
	cout<<ans.size()<<endl;
	for(int x:ans) cout<<x<<endl;
	return 0;
}