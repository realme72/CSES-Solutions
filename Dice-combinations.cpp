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
		for (int j=1; j<=6 ; ++j ){
			 if ((i-j)>= 0 ) dp[i] += dp[i-j]; //the number of ways to make sum x ending with a 3 is dp[x-3].
			//Summing over the possibilities gives dp[x] = dp[x-1] + dp[x-2] + dp[x-3] + dp[x-4] + dp[x-5] + dp[x-6].
			dp[i] %= mod;
		}
	}

	cout << dp[n] << "\n";

	return 0;
} 
