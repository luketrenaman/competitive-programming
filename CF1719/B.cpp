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

int qm(int rem, int div){
	rem += div;
	if(rem % 4 == 0){
		return 4;
	}
	if(rem % 2 == 0){
		return 2;
	}
	return 1;
}
void solve() {
    int n,k;
    cin >> n >> k;
    k = k % 4;
    if(k == 0){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 1;i<=n;i+=2){
		if((i+k)*(i+1) % 4 == 0){
			cout << i << ' ' <<i+1 << '\n';
		} else{
			cout << i+1 << ' ' << i << '\n';
		}
	}
	
	
		
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
