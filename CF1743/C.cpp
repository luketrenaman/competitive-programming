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
    string lid;
    cin >> lid;
    vector<int> vals(n);
    int s = 0;
    for(int i = 0;i<n;i++){
		cin >> vals[i];
	}
	if(lid.find('0') == -1){
		for(int i = 0;i<n;i++){
			s += vals[i];
		}
		cout << s << '\n';
		return;
	}
		
	//lid sections not separated by 0 influence each other
	//for any section its possible to select all but one value
	//so for each subsection, find its sum, and subtract the minimum
	int ss = 0;
	int low = INT_MAX;
	for(int i = n-1;i>=0;i--){
		ss += vals[i];
		low = min(vals[i],low);
		if(lid[i] == '0'){
			s += ss - low;
			ss = 0;
			low = INT_MAX;
		}
	}
	if(lid[0] == '1'){
		s += ss;
	}
	cout << s << '\n';
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
