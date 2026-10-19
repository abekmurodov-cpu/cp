#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>> n;
        vector<int> v;
        for(int i = 1; i<=n ;i++){
            char c;
            cin>>c;
            if(c == '1'){

                v.push_back(i);
                
            }
        }
        if(v.size()>1){
            sort(v.begin(),v.end());
            
            cout<< v[n] - v[0];

            
        }
        else{cout<< 0;}
    }
}