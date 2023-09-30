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

void solve() {
    int n;
    cin >> n;
    //000 --> 100 | 010 | 001
    //001 --> 000 | 011 | 101
    //010 --> 110 | 000 | 011
    //011 --> 111 | 001 | 010
    //100 --> 000 | 110 | 101
    //101 --> 001 | 100 | 111
    //110 --> 010 | 100 | 111
    //111 --> 011 | 101 | 110
    //000 --> 001 --> 011 --> 111 --> 101 --> 100 --> 110 --> 010
    set<int> c;
    for(int i = 0;i<1<<n;i++){
		c.insert(i);
	}
	int start = 0;
	while(c.size() > 0){
		int startCopy = start;
		for(int i = n-1;i>=0;i--){
			cout << ((startCopy >> i) & 1);
		}
		cout << '\n';
		c.erase(start);
		//Test bit modifications at all locations in this integer
		for(int i = 0;i<n;i++){
			int cFlip = start;
			cFlip ^= 1 << i;
			if(c.find(cFlip) != c.end()){
				start = cFlip;
				break;
			}
		}
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
