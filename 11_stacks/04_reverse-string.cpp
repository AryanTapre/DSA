//TODO: Reverse a given input String using Stack

#include<iostream>
#include<stack>
using namespace std;

int main() {

    string input = "aryan";
    stack<char> stack;

    for(auto i : input) {
        stack.push(i);
    }

    input.clear();
    
    while(!stack.empty()) {
        input.push_back(stack.top());
        stack.pop();
    }
    
    cout<<input<<endl;

return 0;
}