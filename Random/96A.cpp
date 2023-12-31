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
    char crt = s[0];
    int lt = 1;
    bool safe = true;
    for(int i = 1;i<s.length();i++){
		if(crt == s[i]){
			lt++;
		} else{
			crt = s[i];
			lt = 1;
		}
		if(lt == 7){
			safe = false;
		}
	}
	cout << (!safe ? "YES" : "NO");
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
