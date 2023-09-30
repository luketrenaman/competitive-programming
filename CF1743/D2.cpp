#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    //Test several leftmost ones aligned with leftmost 0
    //Evaluate bitwise or
    int f0 = -1;
    for(int i = 0;i<n;i++){
		if(s[i] == '0'){
			f0 = i;
			break;
		}
	}
	if(f0 == -1){
		cout << s << '\n';
		return;
	}
	string ans = s;
	for(int i = 0;i<n;i++){
		string cons = s;
		//Construct a string starting at s[0], s[1], s[2].. s[n]
		//Correlate this to f0 plus some offset
		dbg(i);
		//test s[0] against s[f0], s[1] against s[f0+1]
		for(int j = i;j<n&&f0+j-i<n;j++){
			if(s[j] == '1'){
				cons[f0+j-i] = '1';
			}
		}
		ans = max(ans,cons);
	}
	if(ans[0] == '0') cout << 0;
	else cout << ans;
    
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
