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
    string s;
    cin >> s;
    int up = 0;
    int low = 0;
    for(int i = 0;i<sza(s);i++){
		if(isupper(s[i])) up++;
		else low++;
	}
	bool doLow = low >= up;
	for(int i = 0;i<sza(s);i++){
		if(doLow) cout << (char) tolower(s[i]);
		else cout << (char) toupper(s[i]);
	}
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
