// Find Prev Smaller Element for each element
// if not found then place -1
// google it
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> &input) {
    vector<int> ans;
    if(input.empty() || input.size() == 1) {
        ans.push_back(-1);
        return ans;
    }

    stack<int> st;
    ans.push_back(-1);
    st.push(input.at(0));

    for(int i=1; i<input.size(); i++) {
        if(st.top() < input.at(i)) {
            ans.push_back(st.top());
        } else {
            st.pop();
            st.push(input.at(i));
            ans.push_back(-1);
        }
    }
    
    return ans;
}

int main() {
    vector<int> inp = {15,5,8,7,9};
    vector<int> ans = prevSmallerElement(inp);

    for(auto i : ans) cout<<i<<" ";
    cout<<endl;

return 0;
}