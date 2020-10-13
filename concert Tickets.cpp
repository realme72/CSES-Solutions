// @Author :: Gaurav
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define empb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
const int MAX = 1e5+10;


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

ll n, m;

// ll checkForExistence(vector<ll> &tprice, ll &prc) {
// 	ll l = 0, r = n-1, m;

// 	while(l < r && ) {
// 		m = l + ( ( r - l) >> 1 ) ; 
// 		if(tprice[m] > prc) l = m + 1;
// 		else if( tprice[m] < prc) r = m - 1;
// 	}

// 	if(mp[tprice[m]]) {
// 		mp[tprice[m]]--;
// 		return tprice[m];
// 	}

// 	return -1;
// }


void solve() {
	cin >> n >> m;
	vector<ll> tprice(n);
	set<array<ll,2>> s;
 
	for(ll i = 0; i < n; ++i) {
		cin >> tprice[i];
		s.insert({tprice[i], i});
	}
	sort(all(tprice));
	
	ll custPrice;
	for(ll i = 0; i < m; ++i) {
		cin >> custPrice;
		auto l = s.lower_bound({custPrice + 1, 0}) ;
		if(l == s.begin()) {
			cout << "-1\n";
		} 
		else {
			--l ;
			cout << (*l)[0] << "\n";
			s.erase(l);	
		}
	}
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
