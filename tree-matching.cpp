#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define empb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
inline ll binpow(ll a, ll b) {ll res = 1;while(b) {if(b&1) {res = res * a;}a = a* a,b = b >> 1;}return res;}
 
void isKthBitSet(int n, int k) { 
    if (n & (1 << (k - 1))) cout << k-1 << "\n"; 
} 
const int N = 2e5+10;
 
vector<ll> g[N];
ll n;
ll dp1[N], dp2[N];
 
void dfs(int v = 0, int p = -1) {
	for(auto u : g[v]) {
		if(u == p) {
			continue;
		}
		dfs(u, v);
		dp2[v] = max(dp2[v] + max(dp1[u], dp2[u]),dp1[u] + dp1[v] + 1);
		dp1[v] += max(dp1[u], dp2[u]);
	}
}
 
void solve() {
	cin >> n;
	for(ll i = 0; i < n - 1; ++i) {
		ll x, y ; cin >> x >> y; 
		--x,--y;
		g[x].pb(y);
		g[y].pb(x);
	}
 
	dfs();
	cout << max(dp1[0], dp2[0]) << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	// clock_t begin, end;
	// double time_spent;
 
	// begin = clock();
 
	ll t = 1;
	while(t--) {
 
		solve();
	}
 
	// end = clock();
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// cout << "Time Taken " << prec(10) << time_spent;
	// cout << "\n";
	return 0;
}
