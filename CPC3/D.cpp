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
void process(vector<string> s){
	map<int,int> ans;
	for(int i = 0;i<sza(s);i++){
		for(int j = 0;j<sza(s[i]);j++){
			if(s[i][j] == '*'){
				ans[i]++; //Quantity of * in row i
			}
		}
	}
	vector<string> out(s.size());
	//Construct output array of strings
	for(auto it = ans.rbegin();it!=ans.rend();it++){
		int val = it->first; //Index of the row
		int amt = it->second; //Amount of items in this row
		for(int i = 0;i<amt;i++){
			for(int j = 0;j<sza(out);j++){
				if(j == val){
					out[j] += '*';
				} else{
					out[j] += '.';
				}
			}
		}
	}
	for(int i = 0;i<sza(out);i++){
		cout << out[i] << '\n';
	}
}
void solve() {
    vector<string> s;
    string q;
    while(getline(cin,q)){
		if(q == ""){
			process(s);
			s.clear();
			cout << '\n';
		} else{
			s.push_back(q);
		}
	}
	process(s);
}

int main() {
    //std::ifstream in("tc.txt");
    //std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    //std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
