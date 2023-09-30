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
    int r,c,n;
    cin >> r >> c >> n;
    vector< vector <int> > v(r, vector <int> (c, 0));
    queue<pair<int,int>> q;
    for(int i = 0;i<n;i++){
		int r_, c_;
		cin >> r_ >> c_;
		r_--;
		c_--;
		q.push(make_pair(r_,c_));
		v[r_][c_] = -1;
	}
	int highest = 0;
	while(!q.empty()){
		int rt = q.front().first;
		int ct = q.front().second;
		int lvl = v[rt][ct];
		if(lvl == -1) lvl = 0;
		q.pop();
		if(rt<r-1&&v[rt+1][ct]==0){
		v[rt+1][ct] = lvl+1;
		q.push(make_pair(rt+1,ct));
		}
		if(rt > 0&&v[rt-1][ct]==0){
		v[rt-1][ct] = lvl+1;
		q.push(make_pair(rt-1,ct));
	}
		if(ct<c-1&&v[rt][ct+1]==0){
		v[rt][ct+1] = lvl+1;
		q.push(make_pair(rt,ct+1));
	}
		if(ct > 0&&v[rt][ct-1]==0){
		v[rt][ct-1] = lvl+1;
		q.push(make_pair(rt,ct-1));
	}
		
	}
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			//cout << v[i][j] << ' ';
			highest = max(highest,v[i][j]);
		}
		//cout << '\n';
	}
	cout << (highest+1) << '\n';
	
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
