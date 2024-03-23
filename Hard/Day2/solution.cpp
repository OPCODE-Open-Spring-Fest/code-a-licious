#include <bits/stdc++.h>
#define LL long long
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;

const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
 
		/* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};
 
dynamic_hull cht;
int main()
{
	LL n;
	scanf("%lld",&n);
	vector<pair<LL,pair<LL,LL>>>v;
	for(LL a=1;a<=n;a++)
	{
		LL x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		v.push_back(mp(x,mp(y,z)));
	}
	sort(v.begin(),v.end());
	LL mx=0;
	LL dp[n+5];
	for(LL a=0;a<n;a++)
	{
		dp[a]=v[a].fi*v[a].se.fi-v[a].se.se;
		if(a!=0)
		{
			dp[a]=max(dp[a],v[a].fi*v[a].se.fi-v[a].se.se+cht.eval(v[a].se.fi));
		}
	//	printf("dp[%lld]=%lld\n",a,dp[a]);
		cht.insert_line(-v[a].fi,dp[a]);
		mx=max(mx,dp[a]);
	}
	cout<<mx<<endl;
	
}
