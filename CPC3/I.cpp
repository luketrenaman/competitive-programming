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
    map<string,int> variables;
    string q;
    while(getline(cin,q)){
		stringstream ss(q);
		string token;
		ss >> token;
		//cout << token << '\n';
		if(token == "define"){
			int val;
			ss >> val;
			string name;
			ss >> name;
			variables[name] = val;
		} else if(token == "eval"){
			string f,c,s;
			ss >> f >> c >> s;
			if(variables.count(s) == 0 || variables.count(f) == 0){
				cout << "undefined";
			} else{
				int f_ = variables[f];
				int s_ = variables[s];
				if(c == ">"){
					cout << (f_ > s_ ? "true" : "false");
				} else if(c == "<"){
					cout << (f_ < s_ ? "true" : "false");
				} else{
					cout << (f_ == s_ ? "true" : "false");
				}
			}
			cout << '\n';
		}
	}
}

int main() {
	//std::ifstream in("tc.txt");
    //std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    //std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    //ios_base::sync_with_stdio(0);
    //in.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
