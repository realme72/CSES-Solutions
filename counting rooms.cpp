#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)


int n,m;
string g[2500];
bool vis[2500][2500];


void floodfill(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#' || vis[x][y]) return;
    vis[x][y] = 1;
    floodfill(x, y + 1);
    floodfill(x, y - 1);
    floodfill(x - 1, y);
    floodfill(x + 1, y);
}

void solve() {
   	cin >> n >> m;
    for(int i = 0; i < n; ++i) {
    	cin >> g[i];
    }
    int ans = 0;

    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
    	if (g[i][j] == '.' && !vis[i][j]) {
    		floodfill(i,j);
        	ans ++;
    	}
    }
    cout << ans;
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
  
