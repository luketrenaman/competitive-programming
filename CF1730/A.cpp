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
    map<int,int> orbits;
    int n,c;
    cin >> n >> c;
    for(int i = 0;i<n;i++){
		int q;
		cin >> q;
		orbits[q]++;
	}
	int total = 0;
	for(auto it = orbits.begin(); it != orbits.end();it++){
		int freq = it->second;
		if(freq > c){
			total += c;
		} else{
			total += freq;
		}
	}
	cout << total << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
