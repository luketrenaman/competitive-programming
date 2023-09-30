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
    int n = 1000000;
    vector<bool> prime(n+1,true);
    for(int i = 2;i*i<=n;i++){
		if(!prime[i]) continue;
		for(int j = 2*i;j<=n;j+=i){
			prime[j] = false;
		}
	}
	vector<int> superPrimes;
	set<string> primeSet;
	for(int i = 2;i<=n;i++){
		if(prime[i]){
			primeSet.insert(to_string(i));
		}
	}
	for(auto it = primeSet.begin(); it != primeSet.end(); it++){
		string val = *it;
		bool isGood = true;
		for(int i = 1;i<val.size();i++){
			if(primeSet.count(val.substr(i,val.size()-i)) == 0){
				isGood = false;
			}
		}
		for(int i = val.size() - 1;i>=0;i--){
			if(primeSet.count(val.substr(i)) == 0){
				isGood = false;
			}
		}
		if(isGood) superPrimes.push_back(stoi(val));
	}
	int sum = 0;
	for(int i = 0;i<superPrimes.size();i++){
		cout << superPrimes[i] << '\n';
		sum += superPrimes[i];
	}
	cout << sum << '\n';
}

int main() {
    solve();
}
