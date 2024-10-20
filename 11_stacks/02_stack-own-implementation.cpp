#include<iostream>
using namespace std;

class Stack {
    private:
        int *storage;
        int size;
        int top;

    public:
        Stack(int _size) {
            storage = new int[_size];
            this->top = -1;
            this->size = _size;
        }

        // push
        void push(int data) {
            if((size-top)-1 == 0) { // stack is full !
                cout<<"overflow!"<<endl;
                return;
            }
            storage[++top] = data;
            cout<<"current top : "<<top<<endl;
        }

        //pop
        void pop() {
            if(top == -1) { // stack is empty!
                cout<<"underflow"<<endl;
                return;
            }
            --top;
        }
        
        int getTop() {
            if(empty()) return -1;
            
            return storage[this->top];
        }
        
        // empty
        bool empty() {
            bool status = top == -1 ? true : false;
            return status;
        }
        // size

        int getSize() {
            int spaceAvailable = size - top - 1;
            int currentSize = size - spaceAvailable;
            return currentSize;
        }
};

int main() {

    Stack *stack = new Stack(5);

    cout<<stack->getSize()<<endl;
    
    stack->push(19);
    stack->push(10);
    stack->push(20);
    stack->push(90);
    stack->push(80);
    stack->push(100);

    cout<<stack->getSize()<<endl;
    cout<<"top:"<<stack->getTop()<<endl;
    cout<<"empty:"<<stack->empty()<<endl;


    cout<<stack->getTop()<<endl;
    cout<<endl<<"priting the stack ==>"<<endl;
    while(!stack->empty()) {
        cout<<stack->getTop()<<" ";
        stack->pop();
    }
    cout<<endl;

    // stack->pop();
    // stack->pop();
    // stack->pop();
    // stack->pop();
    // stack->pop();
    // stack->pop();


    cout<<stack->getSize()<<endl;
    cout<<"top:"<<stack->getTop()<<endl;
    cout<<"empty:"<<stack->empty()<<endl;

return 0;
}