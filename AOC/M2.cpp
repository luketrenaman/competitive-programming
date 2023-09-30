#include <bits/stdc++.h>

using namespace std;

bool isPrime(int orig, int n){
	if(n == 1){
		return true;
	}
	if(orig % n == 0){
		return false;
	}
	return isPrime(orig,n-1);
}

int main() {
	int n;
	cin >> n;
	cout << (isPrime(n,n-1) ? "True" : "False");
}
