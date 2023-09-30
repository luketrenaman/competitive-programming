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
    int n;
    cin >> n;
    map<int,int> time;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 0;i<n;i++){
		cin >> b[i];
	}
	for(int i = 0;i<n;i++){
		time[a[i]] = max(time[a[i]],b[i]);
	}
	/* Maintain the location of the
	 * Furthest people on either side
	 * Furthest people on either side with time max_t
	*/
	vector<int> maxLocs;
	int maxAmt = 0;
	for(auto it = time.begin(); it != time.end(); it++){
		int loc = it->first;
		int freq = it->second; //or, the amount of time spent here
		if(freq > maxAmt){
			maxAmt = freq;
			maxLocs.clear();
			maxLocs.push_back(loc);
		} else if(freq == maxAmt){
			maxLocs.push_back(loc);
		}
	}
	//And maxLocs will be sorted
	double center = (maxLocs[0] + maxLocs[maxLocs.size()-1])/2.0;
	double lBound = 1000000000;
	double rBound = -1000000000;
	for(auto it = time.begin(); it != time.end(); it++){
		double loc = it->first;
		double freq = it->second;
		double headStart = maxAmt - freq;
		if(loc < center){
			loc = min(loc+headStart,center); 
		} else if(loc > center){
			loc = max(loc-headStart,center);
		}
		lBound = min(lBound,loc);
		rBound = max(rBound,loc);
	}
	cout << fixed << setprecision(8) << (lBound + rBound) / 2.0 << '\n';
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
