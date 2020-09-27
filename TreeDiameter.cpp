#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define vii vector<int>
#define vbl vector<bool>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define lcm(a,b) a*b/(__gcd(a,b))
#define all(a) a.begin(),a.end()
#define test int t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

int x; 

void df2(int v, int count, bool vis[],int& maxCount,vector<vector<int>> &tree) { 
    vis[v] = true; 
    count++; 
    for (auto u : tree[v]) { 
        if (!vis[u]) { 
            if (count >= maxCount) { 
                maxCount = count; 
                x = u; 
            } 
            df2(u, count, vis, maxCount, tree); 
        } 
    } 
} 
  
void dfs(int v, int n,vector<vector<int>> &tree, int& maxCount) { 
    bool vis[n + 1]; 
    int count = 0; 
    for (int i = 1; i <= n; ++i) vis[i] = false;  
    df2(v, count + 1, vis, maxCount, tree); 
} 
  
int diameter(vector<vector<int>> &tree, int n) { 
    int maxCount = 1; 
    dfs(1, n, tree, maxCount); 
    dfs(x, n, tree, maxCount);   
    return maxCount; 
} 
 
int main() {
   	ItsFUN;

   	int n, u, v, i; cin >> n;
    vector<vector<int>> tree(n+1);

    for(i = 0; i < n-1 ; ++i) {
    	cin >> u >> v;
    	tree[u].pb(v);
    	tree[v].pb(u);
    }

	cout << diameter(tree, n) - 1 << "\n";

   return 0;
}
