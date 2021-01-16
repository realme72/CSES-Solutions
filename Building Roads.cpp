#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)

const int N = 2e5 + 10;
vector<vector<int>> g;
vector<bool> vis(N, false);
int n, m;

void dfs(int v) {
	vis[v] = true;
	for(auto u : g[v]) {
		if(!vis[u]) {
			vis[u] = true;
			dfs(u);
		}
	}
}

void solve() {
	cin >> n >> m;
	g.resize(n+1);
	vis.assign(n+1, false);

	for(int i = 0; i <m; ++i) {
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	int cnt = 0,i;
	vector<int> ans;

	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			ans.pb(i);
			dfs(i);
			++cnt;
		}
	}

	cout << cnt - 1 << "\n";
	if(cnt > 0) {
		for(i = 0; i < cnt;++i) {
			if(ans[i]!=0 and ans[i+1]!=0)cout << ans[i] << " " << ans[i+1] << "\n";
		}
		cout << "\n";
	}
}
 
int gaurav() {
	ios_base::sync_with_stdio(false);
	
	// clock_t begin, end;
	// double time_spent;
	// begin = clock();

	int t = 1;
	while(t--) {
		solve();
	}
 
	// end = clock();
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// cout << "Time Taken " << prec(10) << time_spent;
	// cout << "\n";
	return 0;
} 
