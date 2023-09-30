#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
void solve() {
    int start;
    cin >> start;
    vector<vector<int>> adj(101,vector<int>());
    string q;
    getline(cin,q);
    while(q!="-1"){
		getline(cin,q);
		stringstream ss(q);
		string token;
		ss >> token;
		int loc = stoi(token);
		while(ss >> token){
			adj[stoi(token)].push_back(loc);
		}
	}
	while(adj[start].size() != 0){
		cout << start << " ";
		start = adj[start][0];
	}
	cout << start << " ";
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
