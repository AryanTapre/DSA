// check if Word is Valid After Subsitution
// Leetcode 1003

#include<iostream>
#include<stack>
using namespace std;

void fillStackWithX(stack<char> &st, string &x) {
    for(auto i : x) {
        st.push(i);
    }
}

//TODO: Without Using Stack D.S
//bool isValid(string s) {
            // string t = "abc";
        // int i = 0;

        // while(i < s.size()) {
        //     if(i < t.size()) {
                
        //         if(t[i] != s[i]) {
        //             if(s[i] != 'a') return false;
        //             else {
        //                 t.insert(i,"abc");
        //             }
        //         }

        //     }else {
        //         if(s[i] != 'a') return false;
        //         else {
        //             t+="abc";
        //         }
        //     }
        //     ++i;
        // }

        // if(t.size() == s.size()) return true;
        // else return false;
//}

bool isValid(string s) {
    stack<char> st;
    string x = "abc";

    fillStackWithX(st, x);
    int i = s.size() - 1;

    while(i >= 0) {
        if(st.empty()) {
            if(s[i] != 'c') return false;
            else {
                fillStackWithX(st, x);
                continue;
            }
        }else {
            if(st.top()  == s[i]) st.pop();
            else {
                if(s[i] != 'c') return false;
                else {
                    fillStackWithX(st,x);
                    continue;
                }
            }    
        }
        --i;
    }

    if(st.empty()) return true;
    else return false;
}

int main() {
    string s = "a";

    cout<<isValid(s)<<endl;
return 0;
}