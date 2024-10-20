//TODO: Implement N-stacks using Single Array..
// for this file i am using 2 stacks in single Array

#include<iostream>
using namespace std;

class NStacks {
    private:
        int top1;
        int top2;
        int *storage;
        int size;
    
    public:
        NStacks(int _size) {
            this->top1 = -1;
            this->top2 = _size;
            this->size = _size;
            storage = new int [_size];
        }

        void pushOnStack1(int data) {
            if(this->top1+1 == this->top2) {
                cout<<"overflow! stack 1"<<endl;
                return;
            }
            storage[++this->top1] = data;
        }

        void pushOnStack2(int data) {
            if(this->top2-1 == this->top1) {
                cout<<"overflowed stack 2"<<endl;
                return;
            }
            storage[--this->top2] = data;
        }

        void popFromStack1() {
            if(this->top1 < 0) {
                cout<<"underflowed stack 1"<<endl;
                return;
            }
            --this->top1;
        }

        void popFromStack2() {
            if(this->top2 >= this->size) {
                cout<<"underflowed stack 2!"<<endl;
                return;
            }
            ++this->top2;
        }

        int getTopFromStack1() {
            if(this->top1 < 0) {
                return -1;
            }
            return storage[this->top1];
        }

        int getTopFromStack2() {
            if(this->top2 == this->size) {
                return -1;
            }
            return storage[this->top2];
        }

        bool emptyStack1() {
            bool status = this->top1 < 0 ? true : false;
            return status;
        }

        bool emptyStack2() {
            bool status = this->top2 >= this->size ? true : false;
            return status;
        }

        int getSizeOfStack1() {
            return this->top1 + 1;
        }

        int getSizeOfStack2() {
            return this->size - this->top2;
        } 
};

int main() {

    NStacks *stack = new NStacks(10);
    stack->pushOnStack1(10);


    stack->pushOnStack1(20);
    stack->pushOnStack1(30);
    stack->pushOnStack1(40);
    stack->pushOnStack1(50);
    stack->pushOnStack1(60);
    stack->pushOnStack1(70);
    stack->pushOnStack1(80);
    
    stack->pushOnStack2(23);
    stack->pushOnStack2(24);
    stack->popFromStack2();

    cout<<stack->getTopFromStack2()<<endl;
    cout<<"empty for stack 2: "<<stack->emptyStack2()<<endl;

    stack->popFromStack2();


    cout<<"empty for stack 2: "<<stack->emptyStack2()<<endl;

    cout<<"size of stack1 :"<<stack->getSizeOfStack1()<<endl;
    cout<<"size of stack2 :"<<stack->getSizeOfStack2()<<endl;

    cout<<"empty for stack 1: "<<stack->emptyStack1()<<endl;    
    cout<<"empty for stack 2: "<<stack->emptyStack2()<<endl;    


    // printing all element from stack 1 =>
    cout<<endl<<"printing all element from stack 1 =>"<<endl;
    while(!stack->emptyStack1()) {
        cout<<stack->getTopFromStack1()<<" ";
        stack->popFromStack1();
    }
    cout<<endl<<endl;

    cout<<"size of stack 1 :"<<stack->getSizeOfStack1()<<endl;
    cout<<"empty for stack 1: "<<stack->emptyStack1()<<endl;    


return 0;
}