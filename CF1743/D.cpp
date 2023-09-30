#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
void solve() {
    //It is optimal to turn the first present 0 into 1
    //Then, it is optimal to turn the second 0 into 1
    int n; cin >> n;
    string s; cin >> s;
    vector<int> dist1;
    int l1 = -1;
    vector<int> dist0;
    int l0 = -1;
    for(int i = 0;i<n;i++){
		if(s[i] == '1'){
			if(l1 != -1){
				dist1.push_back(i - l1);
			}
			l1 = i;
		}
		if(s[i] == '0'){
			if(l0 != -1){
				dist0.push_back(i - l0);
			}
			l0 = i;
		}
	}
	if(dist1.size() == 0){
		cout << 0 << '\n';
		return;
	}
	if(dist0.size() == 0){
		cout << s << '\n';
		return;
	}
	/*for(int i = 0;i<dist1.size();i++){
		cout << dist1[i] << ' ';
	}
	cout << '\n';
	for(int i = 0;i<dist0.size();i++){
		cout << dist0[i] << ' ';
	}
	cout << '\n';*/
	//Now, dist0[0] will be the first distance we care about
	//We want to see if this matches any distance between 1s
	int maxMatch = 0;
	for(int i = 0;i<dist1.size()&&maxMatch<dist0.size();i++){
		int matches = 0;
		int distsum = 0;
		for(int j = i;j<dist1.size();j++){
			distsum += dist1[j];
			dbg(distsum);
			
			if(distsum == dist0[matches]){
				matches++;
				maxMatch = max(matches,maxMatch);
				distsum = 0;
			}
		}
	}
	maxMatch += 1;
	bool first = false;
	for(int i = 0;i<n;i++){
		if(s[i] == '1'){
			cout << '1';
			first = true;
		} else if(s[i] == '0' && maxMatch > 0){
			maxMatch--;
			cout << '1';
		} else if(first){
			cout << '0';
		}
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
