// Que: Insert current top of stack at the bottom 

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottomHelper(stack<int> &st, int &initCurrentTop, int &initCapacity) {
    if(st.empty()) {
        st.push(initCurrentTop);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtBottomHelper(st, initCurrentTop, initCapacity);

    // backtracking over here
    if(st.size() < initCapacity) 
        st.push(temp);
}

void insertAtBottom(stack<int> &st) {
    int initCapacity = st.size();
    int initCurrentTop = st.top();

    insertAtBottomHelper(st, initCurrentTop, initCapacity);
}

int main() {

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    insertAtBottom(st);

    while(!st.empty()) {
        cout<<st.top() <<" ";
        st.pop();
    }
    cout<<endl;
    

return 0;
}