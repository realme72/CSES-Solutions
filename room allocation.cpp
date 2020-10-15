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
 
void solve() {
	int n; cin >> n;
	vector<pair<int,int>> in(n), out(n);
 
	set<int> s;
 
	for(int i = 0; i < n; ++i) {
		cin >> in[i].first >> out[i].first;
		in[i].second = out[i].second = i;
		s.insert(i);
	}
 
	sort(all(in));
	sort(all(out));
 
	vector<int> ans(n);
	for(int i = 0, j = 0; i < n; ++i) {
		while( j < n && out[j].first < in[i].first) {
			s.insert(ans[out[j].second]);
			++j;
		}
		ans[in[i].second] = *s.begin(); 	
		s.erase(s.begin());
	}	
 
	int tot = *max_element(all(ans)) ;
	cout << tot + 1 << "\n";
	for(int i = 0 ; i < n; ++i) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
}
 
int main() {
   	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
   	int t = 1;	
   	while(t--) {
   		solve() ;
   	}
 
	return 0;
} 
