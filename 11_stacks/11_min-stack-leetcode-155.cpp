// leetcode: min stack 155

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class MinStack {
    private:
        vector<pair<int, int>> stack; // pair.first: current top val, pair.second: minimum value uptill now..

    public:
        void push(int val) {
            if(stack.empty()) {
                stack.push_back(pair<int, int>(val,val));

            } else {
                int mini = min(stack.back().second, val);
                stack.push_back(pair<int, int>(val, mini));
            }
        }

        void pop() {
            stack.pop_back();
        }

        int top() {
            return stack.back().first;
        }
        
        int getMin() {
            return stack.back().second;
        }
};

int main() {
    MinStack *minStack = new MinStack();

    minStack->push(-2);
    minStack->push(-0);
    minStack->push(-3);
    cout<<"minumum is :" <<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->top()<<endl;
    cout<<"minumum is :" <<minStack->getMin()<<endl;


return 0;
}