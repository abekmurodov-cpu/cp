#include<iostream>
#include<queue>
using namespace std;
typedef  long long ll;
int main(){

    long long n,k;
    cin >> n;
    cin >> k;
    long long ans = 0;

    priority_queue<ll> q;

    for(ll i = 0; i<n; i++){
        ll p;
        cin >> p;
        q.push(p);



    }
    
    
    

    while(q.top()!=1 && k != 0){
        ll t = q.top();
        q.pop();
        ans += t;
        t = t/2 + t%2;
        q.push(t);

        

        k--;


    }

    cout << ans+k;


}