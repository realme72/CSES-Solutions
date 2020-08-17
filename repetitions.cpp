#include"bits/stdc++.h"
using namespace std;
 
int main() {
	string s; cin >> s;
	int n=s.length();
 
	int res=1;
	int i=0;
 
	while( i < s.size()-1 ) {
		int cnt = 1;
 
		while( s[i] == s[i+1] ) {
			++cnt ;
			++i ;
		}
 
		res = max( res , cnt);
		++i;
 
	}
 
	cout << res << "\n";
 }
