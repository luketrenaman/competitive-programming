#include <bits/stdc++.h>

using namespace std;

int main(){
    float a, b, c;
    
    cin >> a >> b >> c;
    float det = b*b - 4.0*a*c;
    if(det < 0){
        cout << 0;
    } else if(det == 0){
        cout << 1 << ' ' << fixed << setprecision(2) << (-b / (2.0 * a));
    } else{
        float r1 = ((-b - sqrt(det)) / (2.0 * a));
        float r2 = ((-b + sqrt(det)) / (2.0 * a));
        cout << 2 << ' ' << fixed << setprecision(2) << r1 << ' ' << r2;
    }
    
    return 0;
}
