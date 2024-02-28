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
    ll n,k,p;
    cin >> n >> k >> p;
    //from 1
    vector<ll> sol;
    //consider the case n = k = p = 10^11
    //the answer would simply be all factors of n
    //find a way to calculate the factors of n in less than linear time
    //find all prime factors of n (and their frequency) to generate a map
    /* add a 1 because duh
     * 2: 5
     * 3: 3
     * 5 : 5
     * Then the prime factorizations are found by the distinct presence (or lack) of certain prime factors
     * 
     * That is, there can be anywhere between (0-5) 2s
     * (0-3) 3s
     * (0-5) 5s
     * leading to a total of 6*4*6 (or 144 multiples)
     * this is a LOT better than n = 2^5 * 3^3 * 5^5, or 2700000
     * so let's find the frequency of each prime factor!
     * we can just iterate from n to sqrt(n) (around 10^6), and do this until we have a prime factorization.
     * at most this would take log2(n)*10^6 time, so roughly log(n)srqt(n) which is a whole lot faster
     * */
     map<ll,ll> factor;
     ll c = n;
     for(ll i = 2;i<=min(n,(long long) 1000000);i++){
		 if(c % i == 0){
			 c /= i;
			 factor[i]++;
			 i = 1;
		 }
	 }
	 //if it didn't reduce, c remains as some prime factor
	 if(c != 1){
		 factor[c]++;
	 }
	 
	 //must have n picograms
	 //must not take more than p pils
	 //the number of pills 
	 //now we have a prime factorization which we will store + sort
	 vector<ll> a = {1};
	 if(n/1 <= p) sol.push_back(1);
	 // for each step, multiply the size of a by the number of prime factors you can include
	 // order won't matter here :)
	 for(auto it = factor.begin();it!=factor.end();it++){
		 ll mult = it->first;
		 ll maint = mult;
		 ll amt = it->second;
		 ll sz = a.size();
		 for(ll i = 1; i<=amt;i++){
			 // malong = mult^i
			 for(ll j = 0;j<sz;j++){
				 ll maxMag = a[j] * maint;
				 a.push_back(maxMag);
				 if(
				 maxMag <= k // max amount of magnesium within the actual allowed amount of magnesium
				 && n/maxMag <= p // dividing the target magnesium by magnesium in pills you get the number of pills. Here we check if it's within p, maximum number of pills
				 && n % maxMag == 0 //if its not divisible, this means you'll either be above or below the allowed amount of picograms (bad!!)
				 ) sol.push_back(maxMag);
			 }
			 maint *= mult;
		 }
	 }
	 sort(all(sol));
	 cout << sol.size() << '\n';
	 for(ll i = 0;i<sol.size();i++){
		cout << sol[i] << '\n';
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
