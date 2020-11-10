#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)


int cnt[1000001];

void solve () {
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		cnt[x]++;
	}

	for(int i = 1e6 ; i; --i) {
		int div = 0;
		for(int j = i; j <= 1e6; j += i) {
			div += cnt[j];
		}
		if(div>1) {
			cout << i << "\n";
			return;
		}
	}
}
	

int main() {
	ios_base::sync_with_stdio(false);
	
	// clock_t begin, end;
	// double time_spent;
	// begin = clock();

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
