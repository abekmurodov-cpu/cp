#include<iostream>
#include<vector>
using namespace std;

int main(){

    int x,o;
    cin >> x >> o;

    vector<char> v[3];

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            v[i].push_back('.');
        }
    }

    int second[4][2]  = {{0,0},{0,2},{1,0},{2,1}};
    int first[5][2] = {{0,1},{1,1},{1,2},{2,0},{2,2}};


    if((x>=5 && o>=5) || abs(x-o) > 1){
        cout << "impossible" << endl;
    }
    else{
        if(x>o){
            for(int i = 0; i<x; i++){
                v[first[i][0]][first[i][1]] = 'X';
            }
            for(int i = 0; i<o; i++){
                v[second[i][0]][second[i][1]] = 'O';
            }
        }
        else{
            for(int i = 0; i<o; i++){
                v[first[i][0]][first[i][1]] = 'O';
            }
            for(int i = 0; i<x; i++){
                v[second[i][0]][second[i][1]] = 'X';
            }
        }

        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                cout << v[i][j];
            }
            cout << endl;
        }
        
    }
}