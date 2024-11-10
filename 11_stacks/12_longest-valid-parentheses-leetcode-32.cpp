// leetcode: 32 HARD

#include<iostream>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
        int maxi = 0;
        stack<int> st;
        st.push(-1);

        for(int i=0; i<s.length(); i++) {
            if(s.at(i) == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }else {
                    maxi = max(maxi, i - st.top());
                }
            }
        }
        return maxi;
}

int main() {

    string s = "";
    cout<<longestValidParentheses(s)<<endl;

return 0;
}