// following solution will give you WA at test case 9, that input file is too large so i didn't check, if you find out the bug please mention it.
#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

bool sortByVal (const pair <char, int> &a, const pair <char ,int> &b ) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);

	string s,ans=""; cin >> s;
	vector < pair < char, int > > v;
	map < char , int > m;

	int n = s.length();

	int cn1=0;
	for (int i = 0; i < n; ++i ) {
		m[s[i]]++;
	}

	for (auto i : m ) {
		if(i.second == 1) ++cn1;
		else if(i.second & 1) ++cn1;
		v.emplace_back(make_pair(i.first,i.second));
	}

	sort(v.begin(), v.end(), sortByVal);

	for (int i = 0; i < (int ) v.size() ; ++i ) cout << v[i].first << " " << v[i].second << " \n";

	for (int i = 0; i < (int )v.size(); ++i ){
		if(v[i].second == 1) {
			ans += v[i].first;
		}
		if(v[i].second %2 == 0) {
			for(int  j =0; j< v[i].second/ 2; ++ j) {
				ans += v[i].first;
			}
			reverse(ans.begin(),ans.end());
			for(int j = v[i].second /2 ; j < v[i].second ; ++j ) {
				ans += v[i].first;
			}
		}
	}

	if(cn1 > 1) cout << "NO SOLUTION\n";
	else  cout << ans << "\n";

	return 0;
}


// following is the correct solution to the problem.
#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
	ios_base::sync_with_stdio(false);

	int cnt = 0;
	bool ch[26];
	
	string s, ans =""; cin >> s;
    for (int i = 0; i<(int )s.length(); ++i) {
        if (!ch[s[i] - 'A']) {
            ch[s[i] - 'A'] = true;
            cnt++;
        }
        else {
            ans += s[i];
            ch[s[i] - 'A'] = false;
            cnt--;
        }
    }

    if (cnt > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    cout << ans;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (ch[c - 'A']) {
            cout << c;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}


