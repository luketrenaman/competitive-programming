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
int total = 0;
void floodfill(vector<vector<int>>& rumors, int r, int c,int h, int w){
    if(rumors[r][c] == 0 ) return;
	total++;
	rumors[r][c] = 2;
	if(r+1 < h && rumors[r+1][c] == 1){
		floodfill(rumors,r+1,c,h,w);
	}
	if(r-1>=0 && rumors[r-1][c] == 1){
		floodfill(rumors,r-1,c,h,w);
	}
	if(c+1 < w && rumors[r][c+1] == 1){
		floodfill(rumors,r,c+1,h,w);
	}
	if(c-1>=0 && rumors[r][c-1] == 1){
		floodfill(rumors,r,c-1,h,w);
	}
}

void solve() {
    int r,c;
    cin >> r >> c;
    int h;
    cin >> h;
    int w = h;
    std::vector<std::vector<int> > rumors(h,std::vector<int>(w));
    for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			cin >> rumors[i][j];
		}
	}
	floodfill(rumors,r,c,h,w);
	cout << total;
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
