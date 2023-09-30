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
vector<int> boxes;
vector< vector <int> > adj;
int findSize(int loc){
	int size = 1;
	for(int i = 0;i<adj[loc].size();i++){
		size += findSize(adj[loc][i]);
	}
	boxes[loc] = size;
	return size;
}
void solve() {
	int n;
	cin >> n;
	boxes.resize(n,0);
	adj.resize(n,vector<int>());
    vector<int> boxStart;
    for(int i = 0;i<n;i++){
		int q;
		cin >> q;
		//cout << q << ' ';
		if(q != 0){
			adj[q-1].push_back(i);
		} else{
			boxStart.push_back(i);
		}
	}
	for(int i = 0;i<boxStart.size();i++){
		findSize(boxStart[i]);
	}
	int q;
	cin >> q;
	cin.ignore();
	for(int i = 0;i<q;i++){
		string inp;
		getline(cin,inp);
		stringstream ss(inp);
		string token;
		while(ss>>token){
			cout << token << ' ';
		}
		cout << '\n';
	}
	for(int i = 0;i<n;i++){
		cout << boxes[i] << ' ';
	}
	//Evaluate roots as "nodes where q == 0"
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
