#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

int count( vector<int> &a, int n, int x ) { 
    int dp[x+1];  
    memset(dp, 0, sizeof(dp)); 
    dp[0] = 1; 
    for(int i=0; i<n; i++) {
        for(int j=a[i]; j<=x; j++) {
            dp[j] += dp[j-a[i]]; 
            dp[j] = dp[j]%mod;
        }
    }
  
    return table[x]; 
} 

int main() {
	ios_base::sync_with_stdio(false);

	int n, x;cin >> n >> x;
	vector <int> a(n);

	for (auto &i :a)  cin >> i;

	cout << count(a,n,x) << "\n";
	

	return 0;
} 
