#include"bits/stdc++.h"
using namespace std;
#define ll long long


int main() {
	ios_base::sync_with_stdio(false);

	ll t; cin >> t;
	while (t--) {
		ll y, x; cin >> y >> x;

		ll mx = max(x,y);
		ll mn = min(x, y);
		ll ans = (ll) (mx -1) *(mx-1);

		if(mx == mn) ans += mx;
		else if (mx&1) {
			if (x==mx) {
				ans += 2*mx - y;
			}
			else ans += x;
		}
		else {
			if ( y == mx) {
				ans += 2*mx - x;
			}
			else ans += y;
		}

		cout << ans << "\n";
	} 

	return 0;
}
