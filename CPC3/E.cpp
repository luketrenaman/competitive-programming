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
void next(string &s){
	for(int i = s.size()-1;i>=0;i--){
		if(s[i] == 'z'){
			s[i] = 'a';
			continue;
		}
		s[i]++;
		break;
	}
}
void solve() {
    //A <= words <= B
    //1 <= len(word[i]) <= 15
    //num unique words >= B/2
    string s = "aaaaaaaaaaaaaaa";
    int a,b;
    cin >> a >> b;
    for(int i = 0;i<b;i++){
		cout << s << ' ';
		next(s);
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
