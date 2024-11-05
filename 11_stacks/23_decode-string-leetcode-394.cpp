// Leetcode : 394
// Decode String

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string decodeString(string &s) {
    stack<string> st;
    for(auto ch :s){
        if(ch == ']'){
            string repeat = "";
            while(!st.empty() && st.top() != "["){
                string top = st.top();
                repeat += top;
                st.pop();
            }    
            st.pop();

            string k = ""; // numbers to Repeat
            while(!st.empty() && isdigit(st.top()[0])){
                k += st.top();
                st.pop();
            }
            reverse(k.begin(), k.end());
            
            int n = stoi(k);

            string temp = "";
            while (n--){
                temp += repeat;
            }
            st.push(temp);

        }else{
            string temp(1,ch);
            st.push(temp);
        }
    }

    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    string s = "3[a]2[bc]";
    cout<<decodeString(s)<<endl;

return 0;
}