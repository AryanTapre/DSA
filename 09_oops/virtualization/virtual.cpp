/*
1.  Pre-Processing:
2.  Compilation:
        Parsing:Tokens,
        Syntax analysis.
        Semantics analysis,
        Code Generation

3.  Assembly
4.  Linking
5.  Execution
        

        

*/





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