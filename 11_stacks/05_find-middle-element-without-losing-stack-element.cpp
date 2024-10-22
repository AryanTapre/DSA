//TODO: Find the middle element of stack , without compromising any Element!.

#include<iostream>
#include<stack>
using namespace std;




int getMiddleElementHelper(stack<int> &stack, int &totalSize) {
    if(stack.size() == totalSize+1) return stack.top();
    

    int temp = stack.top();
    stack.pop();

    int ele =  getMiddleElementHelper(stack, totalSize);
    stack.push(temp); // backtracking

    return ele;
}

void getMiddleElement(stack<int> &stack) {
    if(stack.empty()) {
        cout<<"stack can't be empty!"<<endl;
        return;
    }
    int totalSize = stack.size() / 2;
    cout<<getMiddleElementHelper(stack, totalSize)<<endl;
}



int main() {

    stack<int> stack;
    stack.push(20);
    stack.push(10);
    stack.push(56);
    stack.push(99);
    

    getMiddleElement(stack);

return 0;
}