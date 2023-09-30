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
    string a,b;
    cin >> a >> b;
    if(a.length() != b.length()){
		cout << "NO";
		return;
	}
	bool same = true;
    for(int i = 0;i<a.length();i++){
		if(a[i] != b[a.length()-1-i]){
			same = false;
		}
	}
	cout << (same ? "YES" : "NO");
	
		
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
