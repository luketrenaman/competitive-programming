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

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    //let us only look at ties
    //For ties n =2, we either have
    //RSSP PSSR RSSR PSSP we can break ties of length two by selecting
    //the element that is not the item left of the tie or the element of the tie
    //So we add one
    //For ties n = 3 we just change the middle element
    //For ties n = 4 we must change at least two elements to break the tie
    //For ties n = 5 we must change at least two elements ...
    
    //A special case is where the elements loop around
    //If there is a case where ALL elements are the same (and n is odd)
    //Then the tie will take at one more swap to validate
    
    //So we find the length of each tie and sum them as:
    //length(tie) / 2
    vector<int> ties;
    string s;
    cin >> s;
    char prev = s[0];
    int sz = 0;
    int lbound;
    int rbound;
    for(int i = s.length()-1;i>=0;i--){
		if(s[i] == prev){
			sz++;
		} else{
			rbound = i;
			break;
		}
	}
	if(sz == s.size()){
		cout << (sz / 2 + sz % 2) << '\n';
		return;
	}
	for(int i = 0;i<s.length();i++){
		if(s[i] == prev){
			sz++;
		} else{
			lbound = i;
			break;
		}
	}
	ties.push_back(sz);
	sz = 0;
	prev = s[lbound];
	for(int i = lbound;i<=rbound;i++){
		if(s[i] == prev){
			sz++;
		} else{
			ties.push_back(sz);
			prev = s[i];
			sz = 1;
		}
	}
	if(sz != 0){
		ties.push_back(sz);
	}
	dbg(ties);
	int ans = 0;
	for(int i = 0;i<ties.size();i++){
		ans += ties[i] / 2;
	}
	cout << ans;
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
