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
    int n,m;
    vector<int> prefix(n);
    int before = -1;
    int ct = 0;
    for(int i = 0;i<n;i++){
		int a;
		cin >> a;
		if(a != before){
			ct++;
		}
		before = a;
		prefix[i] = ct;
	}
	//In O(n^2) calculate the awesomeness at each index i
	//Then, we know each location will be impacted predictably from the query with i,x
	//We can calculate O(n) how subsections will be impacted at a certain index
	//For example, 
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
