#include<iostream>
using namespace std;

class Person {
    private:
        string name;

    public:
        Person(string name) {
            this->name = name;
        }
};

int main() {

    Person* p = new Person();





// int a=50;
// int* b;
// int** c;

// b = &a;
// c = &b;

// cout<<"a address : "<<&a<<endl;
// cout<<"b address : "<<&b<<endl;
// cout<<"c address : "<<&c<<endl;

// cout<<endl<<"value in b : "<<*b<<endl;
// cout<<"value in c : "<<**c<<endl;

int* p = new int;
*p = 50;


cout<<*p<<endl;



return 0;
}