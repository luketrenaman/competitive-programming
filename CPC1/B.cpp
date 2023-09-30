#include <bits/stdc++.h>

using namespace std;

int main() {
    long long b;
    cin >> b;
    long long n;
    cin >> n;
    vector<int> nums;
    if(n == 0){
		cout << 0;
		return 0;
	}
    while(n>0){
		nums.push_back(n%b);
		n/=b;
	}
	for(int i = nums.size()-1;i>=0;i--){
		cout << nums[i];
	}
}
