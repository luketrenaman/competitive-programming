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
    ll n,d;
    cin >> n >> d;
    map<ll,ll>result;
    for(ll i = 0;i<n;i++){
		ll q;
		cin >> q;
		result[q/d]++;
	}
	long long sum = 0;
	for(auto it = result.begin();it!=result.end();it++){
		ll q = it->second;
		sum += q*(q-1)/2;
	}
	cout << sum;
	//1,2,3,4
	//1,2 1,3 1,4
	//2,3 2,4
	//3,4
	
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
