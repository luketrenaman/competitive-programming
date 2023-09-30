#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a;
  cout << "Enter a number in base 10 to convert to base 16\n";
  cin >> a;
  if(a == 0){
    cout << "0\n";
    return 0;
  }
  string hexMap = "0123456789abcdef";
  string b16 = "";
  while(a > 0){
    b16 += hexMap[a%16]; 
    a /= 16;
  }
  reverse(b16.begin(),b16.end());
  cout << b16 << '\n';
  return 0;
}
