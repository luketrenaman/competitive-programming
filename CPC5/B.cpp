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

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
int ic(int a, int b){
	return (a+b-1)/b;
}
void solve() {
    int n;
    cin >> n;
    map<int,int> freq;
    while(n--){
		int q;
		cin >> q;
		freq[q]++;8
2 3 4 4 2 1 3 1

	}
	//Groups of four need their own car
	int cars = freq[4];
	cars += freq[3];
	//Each car carrying 3 can also carry an additional 1
	freq[1] -= freq[3];
	freq[1] = max(0,freq[1]);
	//Each car carrying 2 can also carry an additional 2
	
	int twoMinus = min(freq[2],(int) ceil(freq[1]/2.0));
	cars += twoMinus;
	freq[2] -= twoMinus;
	freq[1] -= twoMinus*2;
	freq[1] = max(0,freq[1]);
	cars += ceil(freq[2]/2.0);
	//The remainder of cars will carry 1
	cars += ceil(freq[1]/4.0);
	
	/*5
	 *1 1 1 1 2 
	 *3*/
	cout << cars << '\n';
	
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
