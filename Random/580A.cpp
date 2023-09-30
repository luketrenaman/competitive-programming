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
	int n;
	cin >> n;
	
	int maxLn = 1;
    int ln = 1;
    int prev;
    cin >> prev;
    for(int i = 1;i<n;i++){
		int q;
		cin >> q;
		if(prev<=q){
			ln++;
			maxLn = max(maxLn,ln);
		} else{
			ln = 1;
		}
		prev = q;
	}
	cout << maxLn;
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
