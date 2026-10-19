#include<iostream>
using namespace std;

int main(){

    long long n , m;
    cin >> n;
    cin >> m;

    if(n == 1 && m == 1){
        cout << 0;

    }
    else if (n%2==0 || m%2==0){
        cout<< 1;
    }
    else if (n == 1 || m == 1){
        cout << 1;
    }
    
    else{
        bool flag = false;
        long long l = (n*m)/2;
        long long k = (n*m)/2 + 1;

        //  cout << l << " " << k << endl;
        
        for(int i = 1; i <= n/2 ; i++){

            if(l%(n-i)==0 || k%(n-i) == 0){
                flag = true;
                break;
            }

        }

        for(int i = 1; i <= m/2 ; i++){

            if(l%(m-i)==0 || k%(m-i) == 0){
                flag = true;
                break;
            }

        }

        if(flag){
            cout << 2;
        }
        else{
            cout << 3;
        }

    }
}