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
    map<int,int> freq;
    int n;
    cin >> n;
    while(n--){
		int q;
		cin >> q;
		freq[q]++;
	}
	//Cars can be formed as
	//{4}, {3,1}, {2,2}, {1,1,2}, {1,1,1,1}
	
	cout << cars;
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
