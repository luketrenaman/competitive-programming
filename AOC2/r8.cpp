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
int thing(int n, int t){
	int result = n;
	for(int i = 1;i<t;i++){
		result *= (n-i);
	}
	return result;
}
void solve() {
    string terms;
    //GRAAAAH GETLINE ??? getline
    getline(cin,terms);
    int deriv;
    cin >> deriv;
    //parse terms as coefficient, polynomial, in array
    bool first = true;
    for(int i = 0;i<terms.length();i++){
		string coefs = "";
		while(terms[i] != 'x' && i < terms.length()){
			coefs += terms[i];
			i++;
		}
		if(coefs == "") coefs = "1";
		int coef = stoi(coefs);
		int pow;
		if(i+1 >= terms.length() || terms[i+1] == ' ') pow = 0;
		else if(terms[i+2] == 'x') pow = 1;
		else{
			i += 2;
			// then it was x
			string pows = "";
			while(terms[i] != ' ' && i < terms.length()){
				pows += terms[i];
				i++;
			}
			pow = stoi(pows);
		}
		// power is 0, just output coefficient
		if(pow-deriv == 0){
			if(!first){
				cout << " + ";
			}
			cout << coef * thing(pow,deriv);
		}
		else if(pow-deriv == 1){
			if(!first){
				cout << " + ";
			}
			//do nothing haha jk
			// we take the current power (3) whose second derivative should be uhhh coeficient 6
			cout << coef * thing(pow,deriv) << "x";
		} else if(pow-deriv > 0){
			if(!first){
				cout << " + ";
			}
			cout << coef * thing(pow,deriv) << "x^" << (pow - deriv); 
		} else{
			//0
			if(first){
				cout << "0";
			} else{
				break;
			}
		}
		first = false;
		//i love addition
		i += 2;
		
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
