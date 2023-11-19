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
    int h,t;
    cin >> h >> t;
    int w = h*2;
    int totalSize = w*2+2;
    for(int i = w;i>=2;i-=2){
		vector<string> construct;
		string part;
		for(int j = 0;j<w;j++){
			if(j == w-i/2){
				part += "\\";
			} else if(j == i/2-1){
				part +="/";
			} else if(i == 2){
				part += "_";
				} else{
				part += " ";
			}
		}
		construct.push_back(part);
		for(int j = 0;j<sza(construct);j++){
			construct[j] = construct[j] + "  " + construct[j];
			cout << construct[j] << '\n';
		}
			
	}
	cout << string(totalSize,' ') << '\n';
	int tWidth = t*2;
	vector<string> teeth(2);
	for(int i = 0;i<2;i++){
		teeth[i] += string((totalSize-tWidth)/2,' ');
		for(int j = 0;j<tWidth;j++){
			if((i+j)%2==0) teeth[i] += '\\';
			else teeth[i] += '/';
		}
		teeth[i] += string((totalSize-tWidth)/2,' ');
	}
	cout << teeth[0] << '\n';
	cout << teeth[1] << '\n';
	//cout << construct << '\n';
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
