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
    string sz;
    getline(cin,sz);
    int size = stoi(sz);
    int w = size*2-1;
    int center = size-1;
    string a, b;
    getline(cin,a);
    getline(cin,b);
    for(int i = 0;i<size;i++){
		for(int j = 0;j<w;j++){
			if(abs(center-j) <= i){
				cout << b;
			} else{
				cout << a;
			}
		}
		cout << '\n';
	}
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
