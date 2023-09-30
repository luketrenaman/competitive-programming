#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    
    cin >> n;
    int one = n/n;
	int zero = one-one;
	int two = one+one;
	int n3 = one+two;
	int n4 = two+two;
	int n5 = n4 + one;
	int n6 = n3*two;
	int n16 = n4*n4;
	int n64 = n16*n4;
	int n96 = n16*n6;
	
	char n98 = char(n96 + two);
	char n102 = char(n96 + n4 + two);
	char n117 = char(n102 + n16 - one);
	char n105 = char(n96 + n6 + n3);
	char n122 = char(n96 + n16 * two - n6);
	char fizz[] = {n102,n105,n122,n122};
	char buzz[] = {n98,n117,n122,n122};
	
	if(n % n3 == zero){
		cout << n102 << n105 << n122 << n122;
	}
	if(n % n5 == zero){
		cout << n98 << n117 << n122 << n122;
	}
	
    //f 102
    //i 105
    //z 122
    //b 98
    //u 117
    
    
    
    return zero;
}
