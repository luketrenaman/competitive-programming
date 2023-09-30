#include <bits/stdc++.h>

using namespace std;

int moves = 0;
vector<vector<int>> adj;
vector<int> marb;
vector<int> children;
int dfs(int v){
	int others = 0;
	for(auto u : adj[v]){
		others += dfs(u);
		marb[v] += marb[u];
		children[v]+=children[u];
	}
	return abs(marb[v]-children[v]) + others;
	
}
void solve(int size) {
	set<int> nodes;
	for (int i = 0; i < size; ++i){
		nodes.insert(i);
	}
	moves = 0;
	adj.clear();
	marb.clear();
	children.clear();
	marb.resize(size);
	adj.resize(size);
	children.resize(size);
	fill(children.begin(),children.end(),1);
	for(int i = 0;i<size;i++){
		int vert;
		cin >> vert;
		vert--;
		int marbles;
		cin >> marbles;
		marb[vert] = marbles;
		int num_adj;
		cin >> num_adj;
		for(int j = 0;j<num_adj;j++){
			int adj_to;
			cin >> adj_to;
			adj_to--;
			adj[vert].push_back(adj_to);
			nodes.erase(adj_to);
		}
	}
    //Run a DFS from some root node
    cout << dfs(*nodes.begin()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string q;
    while(getline(cin,q) && stoi(q) != 0){
		solve(stoi(q));
		cin.ignore();
	}
}
