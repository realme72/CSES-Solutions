#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define prec(n) fixed<<setprecision(n)
 
 ll maxd(ll x) {
 	ll dig = 0;
 	while(x) {
 		if(x%10>dig) {
 			dig=x%10;
 		}
 		x/=10;
 	}
 	return dig;
 }
 
int main() {
	ios_base::sync_with_stdio(false);
 
	ll n; cin >> n; 
	vector <ll> dp(n+1,INT_MAX);
	dp[0]=0;
 
	for(int i=0;i<=n;++i) {
		ll d = maxd(i);
		dp[i]=min(dp[i],dp[i-d]+1);
	}
	cout << dp[n] << "\n";
 
    
