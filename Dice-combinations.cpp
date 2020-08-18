#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	vector <ll> dp(n+1, 0);

	dp[0] = 1;

	for(int i = 1; i<=n; ++i) {
		for (int j=1; j<=6 && (i-j)>= 0 ; ++j ){
			dp[i] += dp[i-j];
			dp[i] %= mod;
		}
	}

	cout << dp[n] << "\n";

	return 0;
} 
