#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define empb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
inline ll binpow(ll a, ll b) {ll res = 1;while(b) {if(b&1) {res = res * a;}a = a* a,b = b >> 1;}return res;}
 
void isKthBitSet(int n, int k) { 
    if (n & (1 << (k - 1))) cout << k-1 << "\n"; 
}
const int N = 2e5 + 10;
array<ll, 2> a[N];
 
void solve() {
	ll n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
 
	sort(a, a + n);
	ll tm = 0, rew = 0;
	for(int i = 0; i < n; ++i) {
		tm += a[i][0];
		rew += a[i][1] - tm;
	}
 
	cout << rew << "\n";
 
}
 
int main() {
   	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
   	ll t = 1; 
   	while(t--) {
   		solve();
   	}
 
	return 0;
} 
