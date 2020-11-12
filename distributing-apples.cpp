#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)

const int m = 1e9 + 7;
const int MAX = 2e6;
ll inv[MAX], fact[MAX], f2[MAX];

// *** distributing m things among n people can be done by (n + m - ) C (n -1) ***//

void fandi( ) {
	inv[1] = 1;
	for(int i = 2; i <= MAX; ++i) {
		inv[i] = m - m/i * inv[m % i] % m;
	}
	fact[0] = fact[1] = 1;
	f2[0] = f2[1] = 1;

	for(int i = 2; i <= MAX; ++i) {
		fact[i] = fact[i - 1] * i % m;
		f2[i] = f2[i - 1] * inv[i] % m;
	}
}	


void solve() {
	ll chi, app; cin >> chi >> app;
	cout << fact[chi + app - 1] * f2[app] % m * f2[chi- 1] % m << "\n";
}
	

int main() {
	ios_base::sync_with_stdio(false);
	
	// clock_t begin, end;
	// double time_spent;
	// begin = clock();

	fandi();

	int t = 1;
	while(t--) {
		solve();
	}

	// end = clock();
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// cout << "Time Taken " << prec(10) << time_spent;
	// cout << "\n";
	return 0;
} 
