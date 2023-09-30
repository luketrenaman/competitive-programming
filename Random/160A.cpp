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
    int n;
    cin >> n;
    vector<int> coins(n);
    int sum = 0;
    for(int i = 0;i<n;i++){
		cin >> coins[i];
		sum += coins[i];
	}
	sort(coins.rbegin(),coins.rend());
	int subsum = 0;
	int ct = 0;
	while(subsum <= sum){
		subsum += coins[ct];
		sum -= coins[ct];
		ct++;
	}
	cout << (ct);
	
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
