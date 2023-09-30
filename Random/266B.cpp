#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    for(int i = 0;i<t;i++){
		//Do the thing
		string s2;
		s2.assign(s);
		for(int j = 0;j<n-1;j++){
			if(s[j] == 'B' && s[j+1] == 'G'){
				s2[j] = 'G';
				s2[j+1] = 'B';
			}
		}
		s.assign(s2);
	}
	cout << s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
