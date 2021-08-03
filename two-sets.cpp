#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)

double round_up(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}


const ll MOD = 1e9 + 7;

ll binexp(ll a, ll b){
	ll res = 1;

	while(b) {
		if(b&1) {
			res = (res * a) % MOD;
		}
		a = a * a;
		a = a % MOD;
		b = b >> 1;
	}

	return res;
}

void solve() {
	ll n; cin >> n;
	ll s = (n * ( n + 1) )>>1;

	vector<ll> v, u;
	map<ll, ll> m;
	if(s&1) {
		cout << "NO\n";
		return ;
	}
	else {
		ll tmp = s/2;
		for(ll i = n; i > 0; --i) {
			if(tmp - i >= 0) {
				tmp -= i;
				m[i] = 1;
				v.push_back(i);
			}
			if(tmp == 0) {
				break;
			}
		}
	}

	for(ll i = 1; i <= n; ++i) {
		if(!m[i]) u.pb(i);
	}
	cout << "YES\n";
	cout << v.size() << "\n";
	for(auto i : v) cout << i << " ";
		cout << endl;
	cout << u.size() << "\n";
	for(auto i : u) {
		cout << i << " ";
	}
	cout << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);

	int t = 1;
	while(t--) {
		solve();
	}

	return 0;
}
