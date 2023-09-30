
#include <iostream>
#include <string>

using namespace std;

int main() {
int t;
cin >> t;
while (t--) {
int n;
string s;
cin >> n >> s;
int index = -1;
for (int i = 0; i < n - 1; i++) {
if (s[i] == 'L' && s[i + 1] == 'R') {
index = i;
break;
}
}
if (index != -1) {
cout << index + 1 << endl;
} else {
if (s[0] == 'L' || s[n - 1] == 'R') {
cout << -1 << endl;
} else {
cout << 0 << endl;
}
}
}
return 0;
}
