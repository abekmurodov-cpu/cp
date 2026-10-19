#include<iostream>
using  namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    int first = min(min(a,b),c);
    ans = ans + abs(3*first - a - b - c);
    cout << ans;
}