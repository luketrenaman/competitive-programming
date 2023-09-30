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
    ll a;
    cin >> a;
    string charWalk = to_string(a);
    int lucky = 0;
    for(int i = 0;i<sza(charWalk);i++){
		if(charWalk[i] == '4' || charWalk[i] == '7'){
			lucky++;
		}
	}
	string charWalk2 = to_string(lucky);
	int lucky2 = 0;
	for(int i = 0;i<sza(charWalk2);i++){
		if(charWalk2[i] == '4' || charWalk2[i] == '7'){
			lucky2++;
		}
	}
	cout << (lucky2 == sza(charWalk2) ? "YES" : "NO");
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
