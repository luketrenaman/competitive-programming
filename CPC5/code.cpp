#define STRT_YEAR 2007
#include <iostream>
int main(){
	int q = 5;
	int a = STRT_YEAR + q;
	int b = q + STRT_YEAR;
	int c = q + 2007;
	int d = 2007 + q;
	
	std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	std::string monkey = "";
	std::cin >> monkey;
	std::cout << "The user said: " << monkey;
	return 0;
}
