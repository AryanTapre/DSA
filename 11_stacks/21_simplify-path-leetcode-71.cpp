// Leetcode 71
// Simplify path

#include<iostream>
#include<stack>
using namespace std;


void reverseStack(string &ans, stack<string> &st) {
    if(st.empty()) return;

    string x = st.top(); st.pop();
    reverseStack(ans, st);
    ans += x;
}

string simplifyPath(string path) {
    stack<string> st;
    int index = 0;

    while(index < path.size()) {
        int startIndex = index;
        int endIndex = index + 1;

        while(endIndex < path.size() && path.at(endIndex) != '/') {
            ++endIndex;
        }
        index = endIndex;

        string subPath = path.substr(startIndex, endIndex - startIndex);

        if(subPath == "/." || subPath == "/") {
            continue;
        }

        if(subPath != "/..") {
            st.push(subPath);
        } else if(!st.empty()) {
            st.pop();
        }
    }

    string ans = st.empty() ? "/" : "";
    reverseStack(ans, st);

    return ans; 
} 

int main() {

    string  str = "/..//../";   
    cout<<simplifyPath(str)<<endl;


return 0;
}