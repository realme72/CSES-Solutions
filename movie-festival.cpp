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
	int n, x, y; cin >> n;
	vector<pair<int, int>> times;

	for(int i = 0; i < n; ++i ) {
		cin >> x >> y;
		times.pb({y, x});
	}

	sort( all (times));

	int lst = 0, ans = 0;
	for(pair<int,int> i : times) {
		if(i.second >= lst) {
			++ans;
			lst = i.first;
		}
	}
	cout << ans << "\n";
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
