
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


//FIXME:  ALTERNATE WAY ! reverse using another stack

// vector<int> findNextSmaller(vector<int> &str) {
//     vector<int> store;
//     if(str.empty() || str.size() ==1) {
//         store.push_back(-1);
//         return store;
//     }

//     stack<int> st;
//     stack<int> ans;
//     st.push(str.back());
//     ans.push(-1);

//     for(int i=str.size()-2; i>=0; i--) {
//         if(st.top() < str.at(i)) {
//             ans.push(st.top());
//         } else {
//             st.pop();
//             st.push(str.at(i));
//             ans.push(-1);
//         }
//     }

//     while(!ans.empty()) {
//         store.push_back(ans.top());
//         ans.pop();
//     }
//     return store;
// }


vector<int> findNextSmaller(vector<int> &str) {
    vector<int> store;
    if(str.empty() || str.size() ==1) {
        store.push_back(-1);
        return store;
    }

    stack<int> st;
    st.push(str.back());
    store.push_back(-1);

    for(int i=str.size()-2; i>=0; i--) {
        if(st.top() < str.at(i)) {
            store.push_back(st.top());
        } else {
            st.pop();
            st.push(str.at(i));
            store.push_back(-1);
        }
    }

    reverse(store.begin(), store.end());
    return store;
}

int main() {
    vector<int> str = {10};
    vector<int> ans = findNextSmaller(str);

    for(auto i : ans) {
        cout<<i <<" ";
    }
    cout<<endl;

return 0;
}