#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];

    if(n == 1){
        cout << "! 1" << endl;
        return 0;
    }

    stack<int> st;

    for(int i=n; i>0; i--){
        st.push(i);
    }
    
    int sum = 0;

    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        cout << "? " << a << ' ' << b << endl;

        int res;
        cin >> res;

        cout << "? " << b << ' ' << a << endl;
        int res2;
        cin >> res2;

        if(res < res2){
            arr[b] = res2;
            st.push(a);
            sum += res2;
        }
        
        else{
            arr[a] = res;
            st.push(b);
            sum += res;
        }
    }

    arr[st.top()] = n*(n+1)/2 - sum;

    cout << "! ";
    for(int i=1; i<=n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}