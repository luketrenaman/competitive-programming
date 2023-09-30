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
    //We must illuminate the 0th space. So pick the lightbulb furthest
    //to the right that can do this.
    //There is no case where a bulb to the left of this one will be more
    //favorable
    
    //Just continue this process i think :)
    
    int m,r,n;
    cin >> m >> r >> n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	int ilum = 0;
	int i = 0;
	int lBound = 0;
	int used = 0;
	while(i < n && ilum < m){
		while(i < n && a[i] - r <= ilum){
			i++;
		}
		i--;
		/*
		 * 1. No double using elements.
		 * 2. No accessing an out of bounds element
		 * 
		 * Solution: Store the theoretical "lowest" usable value
		 *  */
		if(i < lBound || a[i] - r > ilum){
			cout << "IMPOSSIBLE\n";
			return;
		} else{
			ilum = a[i] + r;
			lBound = i + 1;
			used++;
		}
	}
	cout << used << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
