// @Author :- Gaurav Bharti
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
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
 

int main() {
	ItsFUN;

	ll n, m, k;cin >> n >> m >> k;
    vll applicant(n),apartment(m);
    for(auto &i : applicant) cin >> i;
    for(auto &i : apartment) cin >> i;

	sort(all(applicant));
	sort(all(apartment));
    
    ll ans = 0;
    ll i = 0, j = 0;
    while (i < n && j < m){
        if (abs(applicant[i] - apartment[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else if (applicant[i] < apartment[j]){
            i++;
        }
        else{
            j++;
        }
    }

    cout << ans << "\n";

	return 0;
}
