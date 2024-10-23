// GfG practice..

#include<iostream>
#include<stack>
using namespace std;

void insertInSortedStack(stack<int> &st, int &temp, int &initCap) {
    if(st.empty() || st.top() >= temp) {
        st.push(temp);
        return;
    }

    int store = st.top();
    st.pop();

    insertInSortedStack(st,temp,initCap);
        st.push(store);

}

void sortStack(stack<int> &st) {
    if(st.empty()) return;

    int temp = st.top();
    st.pop();
    sortStack(st);

    int initCap = st.size();
    insertInSortedStack(st,temp, initCap);
}

int main() {

    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);

    sortStack(st);

    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

return 0;
}