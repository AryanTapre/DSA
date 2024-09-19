#include<iostream>
using namespace std;

class Base {
    public:
        Base() {
            cout<<"base ctor \n";
        }
        
        virtual ~Base() {
            cout<<"base dtor \n";
        }
};

class Derive: public Base {
    int *a;
    public:
        Derive() {
            a = new int[1000];
            cout<<"derive ctor \n";
        }

        ~Derive() {
            delete[] a;
            cout<<"derive dtor \n";
        }
};

int main() {

    Base* base = new Derive();
    delete base;

return 0;
}