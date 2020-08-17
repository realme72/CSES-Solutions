#nclude"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007
 
set <string > s; // for only single occurence
 
void permute(string a, int l, int r) 
{ 
	// Base case 
	if (l == r) s.insert(a);
	else { 
		// Permutations made 
		for (int i = l; i <= r; i++)  { 
			swap(a[l], a[i]); 
 
			// Recursion called 
			permute(a, l+1, r); 
 
			//backtrack 
			swap(a[l], a[i]); 
		} 
	} 
} 
 
 
int main() {
	ios_base::sync_with_stdio(false);
 
	string str; cin >> str;
	int n = str.size(); 
	permute(str, 0, n-1); 
	set<string > :: iterator it;
 
	cout << s.size() << "\n";
	for(it=s.begin(); it!=s.end();++it) cout << *it << "\n";
  
	return 0; 
} 
