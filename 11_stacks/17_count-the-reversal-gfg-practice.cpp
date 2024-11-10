// GFG practice:
// count the reversal

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int countRev(string s) {
    // check for odd string..
    if(s.size() % 2 != 0) {
        return -1;
    } 

    stack<char> st;
    int count = 0;
    string checker = "";

    for(auto i : s) {
        if(i == '{') st.push(i);
        else {
            if(!st.empty() && st.top() == '{') st.pop();
            else st.push(i);
        }
    }

    if(st.empty()) return count;
    else {
        while(!st.empty()) {
            if(checker.empty()) checker.push_back(st.top());
            else {
                if(st.top() == '}' && checker == "{") {
                    count +=2;
                    checker.clear();
                }else if(st.top() == '{' && checker == "{") {
                    count +=1;
                    checker.clear();
                } else {
                    // st.top() == '}' && checker == "}"
                    count +=1;
                    checker.clear();
                }
            }
            st.pop();
        }
    }
    return count;
}

int main() {
    string s = "}{{}}{{{";
    cout<<countRev(s)<<endl;
return 0;
}