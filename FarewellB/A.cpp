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
    //Optimal gameplay is to try and limit the pancakes the other player
    //Can claim. Wherever Alice plays, Bob will play to try and limit her in her next move
    //If Bob is outside of this range and R_b < L_a he plays at R_b
    //If Bob is outside of this range and L_b > R_a he plays at L_b
    //Alice will claim in a location such that the sum of pancakes
    //On either side is maximal
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	int la, ra, lb, rb;
	cin >> la >> ra >> lb >> rb;
	la--; ra--; lb--; rb--;
	int aliceMax = 0;
	//LMAO WHAT IF WE JUST BRUTEFORCE!!
	for(int i = la;i<=ra;i++){
		
			int lbp = 0;
			dbg(i);
			if(i - 1 >= lb && i - 1 <= rb){
				lbp = i - 1;
			} else{
				lbp = lb;
				if(lbp == i) lbp--;
			}
			lbp += abs(i - 1 - lbp) / 2;

			int rbp = 0;
			if(i + 1 >= lb && i + 1 <= rb){
				rbp = i + 1;
			} else{
				rbp = rb;
				if(rbp == i) rbp++;
			}
			dbg(lbp);
			dbg(rbp);
			
			int bsum = 0;
			for(int j = 0;j<=lbp&&j<n;j++){
				bsum += a[j];
			}
			int bobMax = bsum;
			bsum = 0;
			for(int j = rbp;j<n;j++){
				bsum += a[j];
			}
			bobMax = max(bobMax,bsum);
			dbg(bobMax);
			aliceMax = max(aliceMax,sum - bobMax);
			dbg(aliceMax);
			
		

	}
	cout << aliceMax << '\n';
	
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
