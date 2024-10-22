// reverse the entire stack

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &store, int &csize, int &initCapacity) {
    if(st.size() <= csize) {
        st.push(store);
        return;
    }
    int temp = st.top();
    st.pop();

    insertAtBottom(st, store, csize, initCapacity);

    //backtracking line..
    if(st.size() < initCapacity) {
        st.push(temp);
    }
}

void solve(stack<int> &st, int csize, int &initCapacity) {
    if(csize == initCapacity-1) return;

    insertAtBottom(st,st.top(),csize, initCapacity);
    solve(st,csize + 1, initCapacity);
}

void reverseStack(stack<int> &st) {
    int csize  = 0;
    int initCapacity = st.size();
    solve(st, csize,initCapacity);
}

int main() {

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStack(st);

    // printing the stack..
    while(!st.empty()) {
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;


return 0;
}