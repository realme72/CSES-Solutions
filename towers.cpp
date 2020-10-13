// @Author :: Gaurav
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define empb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
const int MAX = 2e5+10;


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

void solve() {
	ll n; cin >> n;
	ll cube;
	vector<ll> tow;

	for(ll i = 0; i < n; ++i) {
		cin >> cube;
		auto u = upper_bound(tow.begin(),tow.end(), cube);
		if( u == tow.end()) {
			tow.pb(cube);
		}
		else {
			*u = cube;
		}
	}
	cout << tow.size() << "\n";
}

int main() {
   	ios_base::sync_with_stdio(false);
   	cin.tie(0);cout.tie(0);

	int t = 1;
	while(t--) {
		solve();
	}

	return 0;
} 
