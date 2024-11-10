#include<iostream>
using namespace std;

class A {
    private:
        int data;
    public:
        A(int _data): data(_data) {}

        friend class B;        
        
    
};


class B {
    public:
        void getDataFromClassA(A *objA) {
            cout<<objA->data<<endl;
        }
        
};



int main() {

A*  a = new A(10);
B* b = new B();
b->getDataFromClassA(a); // MESSAGE PASSING B/W CLASS A & B


return 0;
}