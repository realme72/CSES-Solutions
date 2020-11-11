#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
 
const int m = 1e9 + 7;
ll f[1000000];
 
void factorials() {
	f[0] = f[1] = 1;
 
	for(int i = 2; i <= 1000000; ++i) {
		f[i] = (f[i-1] * i) % m;
	}
}
 
ll binexp(ll a, ll b) {
	ll res = 1;
	while(b > 0) {
		if (b&1) res = (res * a) % m;
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}
 
void solve() {
	ll a, b; cin >> a >> b;
	ll ans = f[a];
	ans *= binexp(f[b], m - 2);
	ans %= m;
	ans *= binexp(f[a-b], m - 2);
	ans %= m;
	cout << ans << "\n";
}
	
 
int main() {
	ios_base::sync_with_stdio(false);
	
	// clock_t begin, end;
	// double time_spent;
	// begin = clock();
 
	factorials();
 
	int t; cin >> t;
	while(t--) {
		solve();
	}
 
	// end = clock();
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// cout << "Time Taken " << prec(10) << time_spent;
	// cout << "\n";
	return 0;
} 
