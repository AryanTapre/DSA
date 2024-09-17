#include<iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person(string name, int age) { 
            this->age = age;
            this->name = name;

            cout<<"called parameterizec constructors.."<<endl;
        }
        
        //TODO: copy constructor 
        Person(Person &p) {
            this->age = p.age;
            this->name = p.name;
        }

        void getData() {
            cout<<this->age<<endl;
            cout<<this->name<<endl;
        }

        ~Person() {
            cout<<"destructor called.."<<endl;
        }
};

int main() {

    // int* x = new int[56];
    // delete [] x;

    Person* p1 = new Person("aryan",22);
    Person* p2(p1);
    delete p1;
    delete p2;

return 0;
}
