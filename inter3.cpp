#include<iostream>
using namespace std;

int main(){
    int a[] = {2, 4, 3, 9, 5, 25, 7, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    string s;

    int count = 0;

    for(int i=0; i<19; i++){
        cout<< a[i]<<endl;
        getline(cin, s);
        if (s == "yes"){
            count++;
        }

        if (count > 1){
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;


}