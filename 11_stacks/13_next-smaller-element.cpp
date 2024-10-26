
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

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
    vector<int> str = {};
    vector<int> ans = findNextSmaller(str);

    for(auto i : ans) {
        cout<<i <<" ";
    }
    cout<<endl;

return 0;
}