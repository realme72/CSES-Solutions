#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)

vector<vector<int>> g;
vector<int> par;
vector<int> color;
int cs, ce;
int n, m;

bool dfs(int v, int p) {
	color[v]  = 1;
	for(auto u : g[v]) {
		if(u == p) {
			continue;
		}

		if(color[u] == 0) {
			par[u] = v;
			if(dfs(u, v)) {
				return true;
			}
		}
		else {
			if(color[u] == 1) {
				ce = v;
				cs = u;
				return true;
			}
		}
	}
	color[v] = 2;
	return false;
}

void solve() {
	cin >> n >> m;
	g.resize(n+1);
	color.assign(n+1, 0);
	par.assign(n + 1, -1);

	for(int i = 0, u , v; i < m; ++i) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	for(int i = 1; i <= n; ++i) {
		if(color[i] == 0 and dfs(i ,par[i])) {
			break;
		}
	}

	if(cs == -1) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		vector<int> path;
		path.pb(cs);

		for(int i = ce; i != cs; i = par[i]) {
			path.pb(i);
		}
		path.pb(cs);
		reverse(all(path));
		if(path.size() == 2) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		cout << path.size() << "\n";
		for(auto i : path) cout << i << " ";
		return;
	}

}
 
int gaurav() {
	ios_base::sync_with_stdio(false);
	
	// clock_t begin, end;
	// double time_spent;
	// begin = clock();

	int t  = 1;
	while(t--) {
		solve();
	}
 
	// end = clock();
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// cout << "Time Taken " << prec(10) << time_spent;
	// cout << "\n";
	return 0;
} 
  
