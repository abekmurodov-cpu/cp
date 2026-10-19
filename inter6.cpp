#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int ceil, floor, last_ceil, last_floor,mid;
        ceil = 750;
        floor = 250;
        last_ceil = 1000;
        last_floor = 1;
        mid = (ceil + floor) / 2;
        int query_count = 0;

        while (query_count < 9 && last_ceil - last_floor > 1){
        
        

        cout << "? " << ceil << ' ' << floor << endl;
        query_count++;

        int res;
        cin >> res;
        if(res == (ceil+1)*(floor+1)){
            last_ceil = floor;
            mid = (last_floor + last_ceil) / 2;
            floor = (last_floor + mid) / 2;
            ceil = (last_ceil + mid) / 2;
        }
        else if(res == (ceil+1)*(floor)){
            last_ceil = ceil;
            last_floor = floor;
            ceil = (mid+last_ceil) / 2;
            floor = (last_floor + mid) / 2;
            
        }
        else{
            last_floor = ceil;
            mid = (last_ceil + last_floor) / 2;
            ceil = (last_ceil + mid) / 2;
            floor = (last_floor + mid) / 2;
        }
    }

    cout << "? " << last_ceil << ' ' << last_floor << endl;

    int res;
    cin >> res;
    if(res == (last_ceil+1)*(last_floor)){
        cout << "! " << last_ceil << endl;
    }
    else{
        cout << "! " << last_floor << endl;
    }

    







    }
}