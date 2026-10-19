#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    // vector<int> v;
    // vector<int> ans;

    long long A,B;
    
    while(t--){
        cin >> A >> B;
        long long coff = (A-B/2)/B;
        long long first = A*coff;
        long long second = B*coff*(coff+1)/2;
        long long total = first - second;
        cout << total + A << endl;
        // cout<<coff<<endl;

        
    }
    
}