// leetcode : 1047
// remove-all-adjacent-duplicates-in-string-leetcode-1047

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    string ans = "";

    for(auto i : s) {
        if(!st.empty() && st.top() == i) {
            st.pop();
        }else {
            st.push(i);
        }
    }

    if(st.empty()) return ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();    
    }

    reverse(ans.begin(), ans.end());
    return ans;    
}

int main() {
    string str  = "aaaaa";
    
    cout<<removeDuplicates(str)<<endl;
return 0;
}