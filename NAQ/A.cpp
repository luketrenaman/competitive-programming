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
	// number of teams, amount to advance, limit to send per team
    int n,k,c;
    cin >> n >> k >> c;
    map<int, int> a; //team, amount sent
    vector<int> stor;
    vector<int> stuffs(n);
    vector<bool> advances(n);
    for(int i = 0;i<n;i++){
		//team, school
		int t, s;
		cin >> t >> s;
		stuffs[i] = t;
		/*
4 3 2
10 9
5 9 
4 9
3 9
* 
* 
5 3 1
1 3
2 4
3 3
4 4
		 * */
		if(a[s] < c && k > 0){
			a[s]++;
			k--;
			//advance
			advances[i] = true;
		} else{
			//save for later
			stor.push_back(i);
		}
		
		//ID, school
	}
	// the true amount of teams to still send
	for(int i = 0;i<k&&i<stor.size();i++){
		advances[stor[i]] = true;
	}
	for(int i = 0;i<n;i++){
		if(advances[i]){
			cout << stuffs[i] <<'\n';
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
