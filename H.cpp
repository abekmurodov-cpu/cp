#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> v;
    vector<int> copyV;
    vector<int> ans;
    
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    while(t--){
        int n;
        cin >> n;
        v.push_back(n);
        copyV.push_back(n);
    }
    
    sort(copyV.begin(), copyV.end());

    int mid = copyV.size()/2;

    for(int i=0; i<v.size(); i++){
        if(maxHeap.empty() || v[i] < maxHeap.top()){
            maxHeap.push(v[i]);
            if(maxHeap.size()>minHeap.size()+1){
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }

        }
        else{
            minHeap.push(v[i]);
            if(minHeap.size()>maxHeap.size()){
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }
        if(maxHeap.size() > minHeap.size()){
            ans.push_back(maxHeap.top()*2);
        }
        else if(maxHeap.size() < minHeap.size()){
            ans.push_back(minHeap.top()*2);
        }
        else{
            ans.push_back((maxHeap.top() + minHeap.top()));
        }
    }

    
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }


}