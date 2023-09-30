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
    /*The string will always end sorted in descending order
    * It also is true that leading digits are most important for lexigraphical order
    * So first we check our string for the minimum character, then
    * collect digits in nondecreasing order
    * (for example in 314752277691991) we find 1 is the minimum digit and
    * then we are able to extract the prefix 111 everything else *must*
    * be swapped with some digit so we add their frequencies to a map,
    * then combine our prefix with the mapped characters
    */
    string s;
    cin >> s;
    int n = s.size();
    char lowest = s[0];
    int loc = 0;
    
    for(int i = 1;i<n;i++){
		if(s[i] < lowest){
			lowest = s[i];
			loc = i;
		}
	}
	string prefix = "";
	map<char,int> freq;
	map<char,int> elsewhere;
	elsewhere[lowest-1]++;
	for(int i = loc+1; i<n;i++){
		freq[s[i]]++;
	}
	for(int i = 0;i<loc;i++){
		elsewhere[s[i]]++;
	}
	for(int i = loc+1;i<n;i++){
		while(freq[lowest] == 0){
			lowest++;
		}
		if(s[i] == lowest && lowest != '9'){
			elsewhere[s[i]-1]++;
		} else{
			elsewhere[s[i]]++;
		}
		freq[s[i]]--;
	}
	for(auto it = elsewhere.begin();it != elsewhere.end();it++){
		char lt = it->first;
		int f = it->second;
		lt++;
		lt = min(lt,'9');
		for(int i = 0;i<f;i++){
			prefix += lt;
		}
	}
	cout << prefix << '\n';
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
