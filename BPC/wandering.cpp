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
    int pathsPossible = pow(4,n);
    int paths = 0;
    for(int i = 0;i<pathsPossible;i++){
		int cp = i;
		vector<int> comb(n);
		for(int j = 0;j<n;j++){
			int digit = cp % 4;
			comb[j] = digit;
			cp = cp / 4;
		}
		//cout << '\n';
		int rP = 6;
		int cP = 4;
		int visited[rP][cP] = {};
		int r = 0;
		int c = 0;
		bool path = true;
		for(int j = 0;j<n;j++){
			if(comb[j] == 0){
				if(c-1 >= 0 && visited[r][c-1] == 0){
					visited[r][c] = 1;
					c--;
				} else{
					path = false;
					break;
				}
				//left
			} else if(comb[j] == 1){
				if(c+1<cP && visited[r][c+1] == 0){
					visited[r][c] = 1;
					c++;
				} else{
					path = false;
					break;
				}
				//right
			} else if(comb[j] == 2){
				//down
				if(r+1<rP &&visited[r+1][c] == 0){
					visited[r][c] = 1;
					r++;
				} else{
					path = false;
					break;
				}
			} else if(comb[j] == 3){
				//up
				if(r-1>=0&&visited[r-1][c] == 0){
					visited[r][c] = 1;
					r--;
				} else{
					path = false;
					break;
				}
			}
		}
		if(path){
			paths++;
		}
	}
	cout << paths;
    
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
