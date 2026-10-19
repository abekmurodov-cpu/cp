#include<iostream>
#include<utility>
#include<vector>
using namespace std;

pair<int,int> guess(int mul){
    switch(mul){
    case 32:
        return {4,8};
    case 60:
        return {4,15};
    case 64:
        return {4,16};
    case 92:
        return {4,23};

    case 168:
        return {4,42};
    case 120:
        return {8,15};
    case 128:
        return {8,16};

    case 184:
        return {8,23};

    case 336:
        return {8,42};

    case 240:
        return {15,16};

    case 345:
        return {15,23};
    case 630:
        return {15,42};

    case 368:
        return {16,23};

    case 672:
        return {16,42};
    case 966:
        return {23,42};
    default:
        return {-1, -1};
    }
}

int main(){

    cout << "? 1 2" << endl;

    int mul;

    vector<int> v;
    cin >> mul;

    // if (!(cin >> mul) || mul == 0) {
    //     return 0;
    // }

    pair<int,int> guesses = guess(mul);

    int last;

    int cum =1;

    for(int i = 2; i <5; i++){
        cout << "? " << i << ' ' << i + 1 << endl;
        int res;
        cin >> res;
        // if (!(cin >> res) || res == 0) {
        //     return 0;
        // }

        pair<int,int> gu = guess(res);

        if(i == 2){

        if(guesses.first == gu.first){
            swap(guesses.first, guesses.second);
        }

        else if(guesses.second == gu.second){
            swap(gu.first, gu.second);
        }

        else if(guesses.first == gu.second){
            swap(guesses.first, guesses.second);
            swap(gu.first, gu.second);
        }

        


        v.push_back(guesses.first);
        v.push_back(guesses.second);
        // v.push_back(gu.first);
        v.push_back(gu.second);

        cum*=guesses.first;
        cum*=guesses.second;
        cum*=gu.second;

        last = gu.second;
        

        }

        else{
            v.push_back(res/last);
            last = res/last;
            cum*=last;
        }



    }

    v.push_back(7418880/cum);

    cout << '!' << ' ';

    for(int i = 0; i<6; i++){
        cout << v[i] << ' ';
    }
    cout << endl;

}