#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)

const int N = 2e5 + 5;
int n, m; 
vector<vector<int>> g(N), rg(N);
vector<bool> vis(N), viss(N);

void dfs1(int v ) {
	vis[v] = true;
	for(int u : g[v]) {
		if(!vis[u]) {
			dfs1(u);
		}
	}
}

void dfs2(int v) {
	viss[v] = true;
	for(int u : rg[v]) {
		if(!viss[u]) {
			dfs2(u);
		}
	}
}

void solve() {
	cin >> n >> m;
	g.resize(n+1);
	rg.resize(n+1);
	vis.assign(n+1,false);
	viss.assign(n+1, false);

	for(int i = 0;i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		rg[v].pb(u);
	}

	dfs1(1), dfs2(1);

	bool ncg = false, ncrg = false;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i] || !viss[i]) {
			ncg = true;
			break;
		}
	}

	if(!ncg) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) {
				cout << "1 " << i << "\n";
				return ;
			}
		}	
		for(int i = 1; i <= n; ++i) {
			if(!viss[i]) {
				cout << i << " 1" << "\n";
				return ;
			}
		}
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

/*
4 5
1 2
2 3
3 1
1 4
3 4
*/
