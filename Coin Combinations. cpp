#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007
 
 
int main() {
	ios_base::sync_with_stdio(false);
 
	ll rq, sum; cin >> rq >> sum ;
	vector <ll> a(rq);
 
	for (auto &i : a) cin >> i;
 
	vector <ll> dp(sum+1,INT_MAX);
	dp[0]=0;
 
	for(int i=1; i<=sum; ++i ) {
		for (int j = 0; j< rq; ++j) {
			if(i-a[j]>=0){
				dp[i] = min ( dp[i] , dp[i-a[j]] + 1);
			}
		}
	}
	
	if (dp[sum] != INT_MAX) cout << dp[sum] << "\n";
	else cout << "-1\n";
 
	return 0;
} 
