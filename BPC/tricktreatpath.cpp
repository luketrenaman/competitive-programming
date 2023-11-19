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
// Macro to define a vector of float
#define vp vector<pair<int, float> >
 
vector<vector<float>> findProbability(vector<vp>& G, int N,
                      int F, int S, int T)
{
    vector<vector<float> > P(N + 1, vector<float>(T + 1, 0));
 
    P[S][0] = 1.0;
 
    for (int i = 1; i <= T; ++i)
        for (int j = 1; j <= N; ++j)
            for (auto k : G[j])
                P[j][i] += k.second * P[k.first][i - 1];
 
    return P;
}
void solve() {
    int n,s,d,c;
    cin >> n >> s >> d >> c;
    
    //pham code
      vector dp(d + 1, vector<double>(s * d + 1));
  for (int i = 1; i <= s; i++) {
    dp[1][i] = 1.0 / s;
  }
  for (int i = 2; i <= d; i++) {
    double tot = 0;
    for (int j = 2; j <= s * d; j++) {
      for (int k = 1; k <= s; k++) {
        if (j - k < 0) break;
        dp[i][j] += dp[i - 1][j - k] / s;
      }
      tot += dp[i][j];
    }
    for (int j = 2; j <= s * d; j++) {
      dp[i][j] /= tot;
    }
  }
  for (int i = 1; i <= s * d; i++) {
    cerr << "Probability of " << i << " is " << fixed << setprecision(8) << dp[d][i] << '\n';
  }
  
    vector<int> visits(n,0);
    // Adjacency matrix
    // The edges have been stored in the row
    // corresponding to their end-point
    vector<vp> G(n+1);
    set<int> noTunnel;
    for(int i = 1;i<=n;i++){
		noTunnel.insert(i);
	}
    cin.ignore();
    for(int i = 0;i<c;i++){
		string tunnel;
		getline(cin,tunnel);
		float tunnels = count(all(tunnel),' ');
		istringstream ss(tunnel);
		int source;
		ss >> source;
		int target;
		
		while(ss>>target){
			//cout << "From position " + to_string(source) + " to " + to_string(target) << '\n';
			//cout << "prob " << 1.0/tunnels << '\n';
			G[target].push_back(make_pair(source,1.0/tunnels));
		}
		noTunnel.erase(source);
	}
	for(auto it = noTunnel.begin();it!=noTunnel.end();it++){
		int source = *it;
		int highestRoll = d*s;
		int lowestRoll = d; //for 6 coins, lowest roll is 6. highest is 12
		//float totalRolls = d*s-d+1; //there is 7 outcomes in this case
		vector<float> hold(n+1,0.0);
		for(int i = lowestRoll;i<=highestRoll;i++){
			int loc = (i+source-1)%n+1;
			//accounts for all possible rolls
			
			hold[loc] += dp[d][i];
		}
		dbg(hold);
		for(int i = 1;i<sza(hold);i++){
			if(hold[i] != 0.0){
				G[i].push_back(make_pair(source,hold[i]));
				//cout << ("From position " + to_string(source) + " to " + to_string(i)) << '\n'; 
				//cout << "prob" << hold[i] << '\n';
			}
		}
	}
	
 
    // N is the number of states
    //dbg(G);
 
    int S = 1, F = 1, T = 100000;
	dbg(G);
    vector<vector<float>> prob = findProbability(G, n, F, S, T);
    //dbg(prob);
    vector<pair<float,int>> ans;
    for(int i = 1;i<=n;i++){
		ans.push_back(make_pair(round(prob[i][100000]*1000.0)/1000.0,-i));
	}
	sort(all(ans),greater<pair<float,int>>());
	for(int i = 0;i<3;i++){
		cout << -ans[i].second << ' ' << fixed << setprecision(3) << ans[i].first << '\n';
	}
	
	
	
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
