// @Author :: Gaurav
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define empb emplace_back
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
const int MAX = 2e5+10;


ll binpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = res * a;
		a = a* a;
		b = b >> 1;
	}
	return res;
}

void isKthBitSet(int n, int k) { 
    if (n & (1 << (k - 1))) cout << k-1 << "\n"; 
}

void solve() {
	int n, x; cin >> x >> n;	
    set<int> s, ans;
    s.insert(0);
    s.insert(x);
    unordered_map<int,int> m;
    m[x]++;
    ans.insert(x);
    for(int i = 0 ; i < n ; i++){
        int inp ; cin >> inp;
        auto l = s.lower_bound(inp);
        int p = *l;
        
        advance(l, -1);
        int y = p - *l;
        if(m[y] == 1){
            ans.erase(y);
            m[y]=0;
        }
        else if(m[y]>1) m[y]--;
        
        ans.insert(p - inp);
        m[p-inp]++;
        ans.insert(inp - *l);
        m[inp - *l]++;
        s.insert(inp);
 
        auto it = ans.end();
        advance(it, -1);
        cout << *it << " ";
    }   
    
    cout << "\n";   
}

int main() {
   	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   	int t = 1;	
   	while(t--) {
   		solve() ;
   	}

	return 0;
} 
