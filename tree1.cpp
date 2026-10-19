#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> tree[100000];

    int nodes;
    cin>> nodes;
    int m;
    cin >>m;
    int cats[nodes+1];
    int cat_check[nodes+1];
    for(int i =1; i<=nodes ; i++){
        cin>> cats[i];
        cat_check[i] = cats[i];
    }

    for(int i = 1; i<nodes; i++){
        int index, child;
        cin >> index >> child;
        tree[index].push_back(child);
    }

    // int cat_sum[nodes];

    // if(cats[0] == 1){
    //     cat_sum[0] == 1;
    // }
    // else {
    //     cat_sum[0] == 0;
    // }

    for (int i = 1; i <=nodes; i++){
        
        for(int child : tree[i]){
            int num_cats = cats[i];
            if(cats[child] > 0){
                num_cats++;
                

            }
            else{
                if(tree[child].size() > 0){
                    num_cats = 0;
                }
                else{
                    num_cats = cats[i];
                }
                
            }
            cats[child] = num_cats;
            
        }


    }

    int ans = 0;

    // for(int i =1; i<= nodes; i++){
    //     cout<<cats[i]<< " ";
    // }
    // cout<< endl;

    for(int i =1; i<=nodes; i++){
        if((tree[i].size() == 0)){

            
            if(cats[i]<=m){
                ans++;
            }
            
            
        }
        
    }

    


    cout << ans << endl;

    
}