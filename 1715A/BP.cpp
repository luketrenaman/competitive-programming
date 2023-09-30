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

void output_many_zeroes(int n){
	for(int i = 0;i<n;i++){
		cout << "0 ";
	}
}
void solve() {
	ll n,k,b,s;
	cin >> n >> k >> b >> s;
	//Here, k > 1
	//Try and satisfy b first
	ll solv = b*k; //now, determine if s is satisfied
	if(solv + (k-1)*n >= s && solv <= s){
		s-=solv;
		for(int i = 0;i<n;i++){
			if(0 == s && i == 0){
				cout << solv << " ";
			}
			else if(0 == s){
				cout << "0 ";
			} else{
				int correctDiff = min(s,k-1);
				if(i == 0){
					cout << solv+correctDiff << ' ';
				} else{
					cout << correctDiff << ' ';
				}
				s-=correctDiff;
			}
		}
	} else{
		cout << -1;
	}
	cout << '\n';
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
