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
//The idea: precompute the awesomeness due to each subsection that starts at i
//Then, when we update at a certain index, we can find:
// * How many subsections are impacted
// * The way in which they are impacted
// Allowing awesomeness to be recomputed in one, O(n) step

/* Algorithm:
 * [1] Create prefix array indicating the number of unique components at location O(n)
 * [2] Precompute awesomeness of all subsections starting at index i O(n^2)
 * [3] Recompute awesomeness based on the changes caused to the prefix array O(nm)
 * So the overall complexity is O(n^2 + nm)
 * */
void solve() {
    int n,m;
	cin >> n >> m;
	vector<int> nums(n);
	vector<int> prefix(n);
	int prev = -1;
	int ct = 0;
	for(int i = 0;i<n;i++){
		cin >> nums[i];
		if(nums[i] != prev){
			prev = nums[i];
			ct++;
		}
		prefix[i] = ct;
	}
	vector<int> sa(n); //subsection awesomeness
	ll ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){ //j = i in the case that the segment is just one number
			sa[i] += prefix[j]-prefix[i]+1;
		}
		ans += sa[i];
	}
	for(int i = 0;i<m;i++){
		int idx,x;
		ll adj = 0;
		cin >> idx >> x;
		idx--;
		vector<int> prefix_tf(n); //transformed prefix array
		int prev_b = -1;
		int ct_b = 0;
		for(int j = 0;j<n;j++){
			int a = nums[j];
			if(idx == j){
				a = x;
			}
			if(a != prev_b){
				prev_b = a;
				ct_b++;
			}
			prefix_tf[j] = ct_b;
			int delta = prefix_tf[j] - prefix[j];
			cout << delta << ' ';
			//We find that if delta is positive then all subsections containing it must increase
			//We know how many subsections this is, we calculate as
			//[x,x,x,x,x]
			//3rd element (j=2)? so first element will contain it in 3 subsections
			//Similarly, the second element will contain it in 3 subsections
			//And third element will contain it in 3 subsections
			//As subsections start from the left, nothing to the left can be contained by this
			//So the delta will then impact the
			adj+=delta*(j+1)*(j+1);
		}
		cout << '\n';
		cout << ans+adj << '\n';
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
