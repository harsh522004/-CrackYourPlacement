#include <bits/stdc++.h>

using namespace std;
vector<int> leaders(int n, int arr[]) {
    stack<int> st;
    st.push(arr[n-1]);
    vector<int> right_big(n,-1);
    for(int i = n-1 ; i >= 0 ; i--){
        if(arr[i] > st.top()){
            st.push(arr[i]);
        }
        
        right_big[i] = st.top();
    }
    
    for(auto i : right_big){
        cout << i << " ";
    }
    
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] >= right_big[i]){
            ans.push_back(arr[i]);
        }
    }
    
    return ans;
    
}
int main() {
    // your code goes here
    int arr[4] = {5, 10, 20, 40};
    vector<int> result = leaders(4 , arr);
    cout << endl;
    for(auto i : result){
        cout << i << " ";
    }
    return 0;
}