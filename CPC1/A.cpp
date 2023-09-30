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
    string s;
    cin >> s;
    int longestPrime = 0;
    int longest = 0;
    int seq = 0;
    for(int i = 0;i<s.length();i++){
		int a = s[i];
		if(a == seq + 1){
			longest++;
		} else{
			longest = 1;
		}
		seq = a;
		longestPrime = max(longest,longestPrime);
	}
	cout << longestPrime;
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
