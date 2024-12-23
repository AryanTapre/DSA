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
    if(csize == initCapacity - 1) return;

    insertAtBottom(st,st.top(),csize, initCapacity); 
    solve(st,csize + 1, initCapacity);    // csize will get increment sequentially at solve call
}

void reverseStack(stack<int> &st) {
    if(st.empty()) {
        cout<<"stack can't be empty!"<<endl;
        return;
    }
    int csize  = 0; // current-stack-size
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