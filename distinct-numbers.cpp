#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	set < ll > s;

	ll x;
	for( ll i =0; i<n ;++i) {
		cin >> x;
		s.insert(x);
	}

	cout << s.size() << endl;

	return 0; 
} 
