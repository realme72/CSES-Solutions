#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define prec(n) fixed<<setprecision(n)
const int mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	vector<vector<char>> a(n,vector<char>(n));

	for(int i = 0; i< n; ++i) {
		for(int j = 0; j<n; ++j) cin >> a[i][j];
	}

	vector<vector<ll>> dp(n+1,vector<ll>(n+1));

	dp[0][0] = 1;

	ll ans = 0;
	for(int i = 0 ; i < n; ++i ){
		for (int j = 0; j< n; ++j) {
			if(a[i][j]=='.') {
				if(i>0)	{
					dp[i][j] += dp[i-1][j] ;
					dp[i][j] %= mod;
				}
				if(j>0) {
					dp[i][j] += dp[i][j-1];
					dp[i][j] %= mod;
				}	
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	cout << dp[n-1][n-1] << "\n";


    return 0;
}
