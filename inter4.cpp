#include<iostream>
#include<set>
#include<map>
#include<stack>
using namespace std;

// struct Node
// {
//     int id;
//     set<int> knows;
// };


int main(){
    int s;
    cin >> s;

    map<int, set<int>> graph;
    set<int> remaining;

    int count = 0;
    
    for (int i = 1; i <= s; i++) {
        int k;
        cin >> k;
        graph[k].insert(i);
        graph[i].insert(k);
        remaining.insert(i);
    }

    stack<int> st;

    while(!remaining.empty()){
        auto it = remaining.begin();
        int id = *it;
        st.push(id);
        remaining.erase(it);
        while(!st.empty()){
            int current = st.top();
            st.pop();
            for (int neighbor : graph[current]) {
                if (remaining.erase(neighbor)) {
                    st.push(neighbor);
                }
            }
            

        }
        count++;
    }

    cout << count << endl;

    
}
