#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007
 
ll binpow(ll a, ll b) {
	ll res=1;
	a%=mod;
	while (b) {
		if(b&1) res = (res * a)%mod;
		a = (a*a)%mod;
		b=b>>1;
	}
 
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
 
 
	ll n; cin >> n;
	cout << binpow(2,n) << "\n" ;
 
 return 0;
 }	
