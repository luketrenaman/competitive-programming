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
    //Sum the number of inversions
    //Given all numbers are distinct, and n = 20, a map is fine
    map<int,int> a;
    vector<int> monkey(20);
    int k;
    cin >> k;
    for(int i = 0;i<20;i++){
		int q;
		cin >> q;
		monkey[i] = q;
	}
	int stepBack = 0;
	for(int i = 0;i<20;i++){
		for(int j = i+1;j<20;j++){
			if(monkey[i] > monkey[j]){
				swap(monkey[i],monkey[j]);
				stepBack++;
			}
		}
	}
	cout << k << ' ' << stepBack << '\n';
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
