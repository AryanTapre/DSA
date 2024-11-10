// Find Next Smaller Element for each element
// if not found then place -1

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

// vector<int> nextSmallerElement(vector<int> &inp) {
//         vector<int> ans(inp.size());
//         stack<int> st;
//         st.push(-1);

//         for(int i=inp.size()-1; i>=0; i--) {
//             while(inp[st.top()] > inp[i]) st.pop();
//             int index = st.top();
//             if(index == -1) index = inp.size();
//             ans.at(i) = index;
//             st.push(i);
//         }
//         return ans;
//     }

int main() {
    vector<int> str = {2,1,5,6,2,3};
    vector<int> ans = findNextSmaller(str);

    for(auto i : ans) {
        cout<<i <<" ";
    }
    cout<<endl;

return 0;
}