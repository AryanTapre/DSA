// Coding ninjas: https://www.naukri.com/code360/problems/redundant-brackets_975473

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isRedundantBracket(stack<char> &st) {
    string operators = "+-*/";
    bool flag = false;

    while(st.top() != '(') {
        for(auto i : operators) {
            if(st.top() == i) {
                flag = true;
                break;
            } 
        }
        st.pop(); //ddsd
    }
    st.pop();
    // hello sir
    if(flag) return false;
    return true;
}

bool findRedundant(string &s) {
    stack<char> st;
    bool sr = false;
    for(auto i : s) {
        if(!(i>='a' && i<='z') && i != ')') {
            st.push(i);
        }else if(i == ')') {
            // pop the stack till you get opening bracket..
            sr = isRedundantBracket(st);
            
        }
        if(sr) return true;
    }
    return false;
}

// void helper(stack<char> &st, bool &status) {
//     string ops = "+-/*";
//     bool localS = false;

//     while(st.top() != '(') {
//         for(auto i : ops) {
//             if(st.top() == i) {
//                 localS = true;
//                 break;
//             }
//         }
//         st.pop();
//     }

//     st.pop();

//     if(localS) {
//         status = false;
//     } else {
//         status = true;
//     }   
// }

// bool findRedundant(string &str) {
//     bool status = false;
//     stack<char> st;
//     for(auto i : str) {

//         if(!(i >= 'a' && i <= 'z') && (i != ')')) {
//             st.push(i);
//         } else if(i == ')') {
//             helper(st, status);
//         }
//         if(status) return true;
//     }
    
//     return false;
// }

int main() {

    string str[] = {"a+((b*c))","(c*b)+a*(a+b)","(a*b)*((c+b)*(d+b))","((a*b)*(c+b))*((d)+b)"};
    for(auto i : str) {
        cout<<findRedundant(i)<<endl;
    }
    

return 0;
}