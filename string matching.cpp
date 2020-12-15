#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb emplace_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)
 
void compute(string t, int m, int lps[]) {
	int len = 0;
	lps[0] = 0;
 
	int i = 1;
	while(i < m) {
		if(t[i] == t[len]) {
			++len;
			lps[i] = len;
			++i;
		}
		else {
			if(len != 0) {
				len = lps[len - 1] ;
			}
			else {
				lps[i] = 0;
				++i;
			}
		}
	}
}
 
 
int kmpSearch(string s, string t) {
	int n = s.length();
	int m = t.length(), c = 0;
 
	int lps[m];
	compute(t, m, lps);
 
	int i = 0;
	int j = 0;
	while(i < n) {
		if(t[j] == s[i]) {
			++j;
			++i;
		}
		if(j == m) {
			++c;
			j = lps[j - 1];
		}
 
		else if( i < n and t[j] != s[i]) {
			if(j != 0) {
				j = lps[j - 1];
			}
			else i += 1;
		}
	}
	return c;
}
 
 
void solve() {
	string s; cin >> s;
	string t; cin >> t;
 
	cout << kmpSearch(s, t) << "\n";
}
 
int gaurav() {
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
