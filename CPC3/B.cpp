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
    int h;
    cin >> h;
    h++;
    
    string s;
    cin >> s;
    //15
    //-1 -2
    //-2 -3 -3 -4
    //-4 -5 -5 -6 -6 -7 -7 -8
    
	int upper = 1 << h;
	int ct = 1;
	for(int i = 0;i<s.length();i++){
		ct <<= 1;
		if(s[i] == 'R'){
			ct++;
		}
	}
	cout << (upper - ct);
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
