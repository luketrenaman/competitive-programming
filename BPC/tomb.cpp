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

vector<int> dist;
vector<vector<ar<int,2>>> adj;
void dijkstra(int s) {
    //dist.assign(n + 1, LINF);
    priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
    dist[s] = 0; pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    } 
}
 /*
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << "\n";
}*/
int nLevel(int n){
	//report number of nodes in a pyramid level
	return (n*(n+1))/2;
}
void solve() {
    int n;
    cin >> n;
    map<int,vector<vector<int>>> tet;
    vector<int> costs;
    
    
    //node at 0 will be our entry point
    int node = 0;
    adj.push_back(vector<ar<int,2>>());
    costs.push_back(0);
    dist.push_back(INT_MAX);
    node++;
    //
    for(int i = n;i>=1;i--){
		dbg(i);
		vector<vector<int>> triangle;
		for(int j = 0;j<i;j++){
			int sz = i-j;
			triangle.push_back(vector<int>(sz,0));
			for(int k = 0;k<sz;k++){
				int q;
				cin >> q;
				costs.push_back(q);
				dist.push_back(INT_MAX);
				triangle[j][k] = node;
				if(i == 1 //top
				||j == 0 || j ==i-1||//top or bottom row
				k==0||k==sz-1){ //left or right side, then entry
					adj[0].push_back({node,costs[node]});
				}
				node++;
				adj.push_back(vector<ar<int,2>>());
			}
		}
		tet[i] = triangle;
	}
	int again = 1;
	for(int i = n;i>=1;i--){
		for(int j = 0;j<i;j++){
			int sz = i-j;
			for(int k = 0;k<sz;k++){
				//The node on layer i, row j, and col k can be connected to
				//on the same layer...
				//i,j-1,k
				//i,j-1,k+1
				//i,j,k-1
				//i,j,k+1
				//i,j+1,k-1
				//i,j+1,k
				//to smaller layer...
				//i-1,j,k
				//i-1,j-1,k
				//i-1,j,k-1
				//to larger layer...
				//i+1,j+1,k
				//i+1,j,k+1
				//i+1,j,k
				//for each connection, check if it exists. then add to adj list
				vector<vector<int>> comb = {
					//on the same layer...
					{i,j-1,k},
					{i,j-1,k+1},
					{i,j,k-1},
					{i,j,k+1},
					{i,j+1,k-1},
					{i,j+1,k},
					//to the smaller layer...
					{i-1,j,k},
					{i-1,j-1,k},
					{i-1,j,k-1},
					//to larger layer...
					{i+1,j+1,k},
					{i+1,j,k+1},
					{i+1,j,k}
				};
				for(int m = 0;m<sza(comb);m++){
					int lvl = comb[m][0];
					int r = comb[m][1];
					int c = comb[m][2];
					//Check if connection exists. If so, add to adj list
					if(lvl>=0 && lvl<=n &&
					r>=0 && r < sza(tet[lvl]) &&
					c>=0 && c < sza(tet[lvl][r])
					){
						adj[tet[lvl][r][c]].push_back({again,costs[again]});
					}
				}
				again++;
			}
		}
	}
	//Now we should be able to access the node ID of
	//level size 4
	//rows indexed by 0
	//cols indexed by 0
	//with tet[level][rows][cols]
	//Then, we expect for n = 4 tet[4][0][3] to be 3
	//cout << sza(tet[4][0]);
	dbg(tet);
	//cout << tet[4][0][3];
	dbg(adj[0]);
	dijkstra(0);
	dbg(dist);
	int highest = 0;
	for(int i = 0;i<sza(dist);i++){
		if(dist[i] != 0 && dist[i] > highest){
			highest = dist[i];
		}
	}
	cout << highest;
    
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
