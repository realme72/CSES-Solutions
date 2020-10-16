// @Author :: Gaurav
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define empb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
/*
PREPARE LIKE YOU HAVE NEVER WON BEFORE
AND FIGHT LIKE YOU HAVE NEVER LOST BEFORE.
*/

ll binpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = res * a;
		a = a* a;
		b = b >> 1;
	}
	return res;
}

void isKthBitSet(int n, int k) { 
    if (n & (1 << (k - 1))) cout << k-1 << "\n"; 
}
const int maX = 2e5;
int a[maX], n, t;

void solve() {
	cin >> n >> t;
	for(int i = 0; i < n; ++i) cin >> a[i];

	ll l = 1, r = 1e18;
	while (l < r) {
		ll m = (l + r) / 2, s= 0;
		for(ll i = 0; i < n ; ++i) {
			s += min(m/a[i], (ll)1e9);
		}
		if( s >= t) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	cout << l << '\n';
}

int main() {
   	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   	int t = 1;	
   	while(t--) {
   		solve() ;
   	}

	return 0;
} 
