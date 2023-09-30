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
/*
 1
 9 9
 3 2 1 6 5 4 9 8 7
 1 10
 2 10
 3 10
 4 10
 5 10
 6 10
 7 10
 8 10
 9 10
 
 
 2
 5 1
 5 4 3 2 1
 1 10
 5 1
 4 5 3 2 1
 2 10
 */
void solve() {
    //0 if a participant is less than all left of it
    //otherwise, the number of participants to the right of it with a lower strength
    //if no such participant exists, k-(left of) is the answer
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    map<int,int> mk;
    int gt = -1;
    int gi = -1;
    for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i] > gt){
			gt = a[i];
			gi = i;
		}
		mk[gi]++;
	}
	while(q--){
		int j,k;
		cin >> j >> k;
		if(a[j] == gt){
			//This is the absolute greatest number
			//if in position 1,2, ans = k
			//otherwise, ans = k - j + 2
			int ans;
			if(j <= 2) ans = k; //you win a fight on the left or are already in base position
			else ans = k - j + 2; //if in position 3, you must wait 1 round before winning a fight
			cout << max(ans,0) << '\n'; //if ans is negative, you can't win any rounds; output 0
		}
		else if(mk[j] > 0){
			int roundsWon = mk[j]-1; //mk[j] is inclusive of itself, negate this
			//This number has at least one number to the right of it that is less than it
			//Also a local maximum, so it will sift to the left
			int ans;
			int bonus = 0;
			if(j <= 2){
				ans = k; //if you are in position 1 or 2, the maximum amount of wins will be the number of rounds
			}
			else{
				ans = k - j + 2; //otherwise, you are limited by your position, (position 3 must wait 1 round before winning any fight)
			}
			if(j >= 2){
				bonus = 1; //you win one round on the left
			}
			//This is just the upper bound of winnable rounds
			ans = max(ans,0);
			cout << min(roundsWon+bonus,ans) << '\n';
		} else{
			//A nothing number
			cout << "0\n";
		}
	}
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
