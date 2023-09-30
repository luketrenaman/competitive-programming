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
    int w,h;
    cin >> w >> h;
    cin.ignore();
    vector<int> b(w);
    for(int i = 0;i<h;i++){
		string q;
		getline(cin,q);
		for(int j = 0;j<w;j++){
			if(q[j] == '#') b[j]++;
		}
	}
	
	int biggest = 0;
	for(int i = 1;i<w-1;i++){
		biggest = max(biggest,b[i-1]+b[i+1]-b[i]);
	}
	cout << biggest;
    
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
