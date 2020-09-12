// @Author :- Gaurav Bharti
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define all(a) a.begin(),a.end()
#define test ll t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
vll t[200001];

void dfs(ll cur, ll parent, vll &req){
	ll numOfSub = 0;
	for(auto u : t[cur]) {
		if(u != parent) {
			dfs(u,cur,req);
			numOfSub += (1+ req[u]);
		}
	}

	req[cur] = numOfSub;
}

int main(){
	ItsFUN;

	ll n; cin >> n;

	for(ll i = 2; i<n+1;++i) {
		ll x ; cin >> x;
		t[x].pb(i);
		t[i].pb(x);
	}

	vll req(n+1,0);

	dfs(1,0,req);

	for(ll i = 1; i<n+1; ++i) cout << req[i] << " ";
	cout << endl;

	return 0;
}
