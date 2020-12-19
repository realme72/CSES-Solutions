#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)
const int N = 1e5 + 10;
const int M = 2e5 + 10;
int n, m;
 
vector<vector<int>> g(N);
 
 
void solve() {
	cin >> n >> m;
	g.resize(n+1);

	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
 
	vector<int> side(n+1, -1);
	queue<int> q;
	bool bp = true;
	for(int i = 1; i <= n; ++i) {
		if(side[i] == -1) {
			q.push(i);
			side[i] = 0;
			while(!q.empty()) {
				int v = q.front();
				q.pop();
				for(auto u : g[v]) {
					if(side[u] == -1) {
						side[u] = side[v] ^ 1;
						q.push(u);
					}
					else {
						bp &= (side[u]!=side[v]);
					}
				}
			}
		}
	}
 
	if(bp) {
		for(int i = 1; i <= n; ++i) cout << side[i] + 1 << " ";
	}
	else cout << "IMPOSSIBLE\n";
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
