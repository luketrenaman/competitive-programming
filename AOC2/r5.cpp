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
    int w,h,idx,n;
    cin >> w >> h >> idx >> n;
    /*- If there is nothing below the sand move down.
- Else if there is nothing diagonally down and right from the sand move down and right.
- Else if there is nothing diagonally down and left from the sand move down and left.
     * 
     * */
     char a[h][w] = {' '};
     for(int r = 0;r<h;r++){
		 for (int c = 0;c<w;c++){
			 a[r][c] = ' ';
		 }
	 }
     for(int i = 0;i<n;i++){
		 int r = 0;
		 int c = idx;
		 while(true){
			 if(r+1 < h && a[r+1][c] != '.'){
				 r++;
			 } else if(r+1 < h && c + 1 < w && a[r+1][c+1] != '.'){
				 r++;
				 c++;
			 } else if(r+1 < h && c - 1 >= 0 && a[r+1][c-1] != '.'){
				 r++;
				 c--;
			 }
			 else{
				 a[r][c] = '.';
				 break;
			 }
		}
	 }
	 for(int r = 0;r<h;r++){
		 for (int c = 0;c<w;c++){
			 cout << a[r][c];
		 }
		 cout << '\n';
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
