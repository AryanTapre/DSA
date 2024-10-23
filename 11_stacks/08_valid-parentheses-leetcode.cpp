// TODO: valid parentheses leetcode: 20

#include<iostream>
#include<stack>
using namespace std;

bool isPairMatch(char &top, char &current) {
    bool status;
    switch(top) {
        case '(':
            if(current == ')') status = true;
            else status = false;
        break;

        case '[':
        if(current == ']') status = true;
            else status = false;
        break;

        case '{':
        if(current == '}') status = true;
            else status = false;
        break;

        default:
            status = false;
        break;
    }
    return status;
}

bool isVaid(string str) {
    stack<char> st;

    for(auto i: str) {
        // pushing all opening bracket onto the stack..
        if(i == '(' || i == '{' || i == '[') st.push(i);
        else {
            if(st.empty()) return false;
            else {
                if(isPairMatch(st.top(), i)) st.pop();
                else return false;
            }
        }
    }

    bool status = st.empty() ? true : false;
    return status;
}

int main() {

    string str = "{}()[]";
    cout<<isVaid(str)<<endl;


return 0;
}