#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
void solve() {
    //code goes here
    int count;
    cin >> count;
    vector<int> coins(count);
    for (int i = 0; i < count; i++) {
        cin >> coins[i];
    }
    int target;
    cin >> target;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int j=0;j<count;j++) {
        for (int i=0;i<dp.size();i++) {
            if (i+coins[j]<=target) {
                dp[i+coins[j]] += dp[i];
            }
            
        }
    }
    cout << dp[target];

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
