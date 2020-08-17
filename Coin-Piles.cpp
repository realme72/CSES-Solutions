#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
	ios_base::sync_with_stdio(false);


	ll t;cin >> t;
	while(t--) {
		ll a, b; cin >> a >> b;
		if( 2 * min(a, b) < max(a, b) ) {
			cout << "NO\n";
		}

		else {
		    a %= 3, b %= 3;
		    if(a < b) swap(a, b);
		    if( (a==2 && b==1) || (a==b && b==0) ) {
		        cout<<"YES\n";
		    }
		    else {
		        cout<<"NO\n";
		    }
		}
	}

	return 0;
}
