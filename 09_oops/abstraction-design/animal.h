#if !defined(animal)
#include <iostream>
using namespace std;

class Terrestrial {
    public:
        void virtual walk() = 0;
        void virtual eat() = 0;
        void virtual speak() = 0;
};

class Bird {
    public:
        void virtual fly() = 0;
        void virtual eat() = 0;
        void virtual speak() = 0;
        
};

class Sparrow: public Bird {
    public:
        void eat() {
            cout<<"Sparrow is eating..\n";
        }
        void fly() {
            cout<<"Sparrow is flying,,\n";
        }
        void speak() {
            cout<<"sparrow is speaking..\n";
        }
};




class Eagle: public Bird {
    public:
        void eat() {
            cout<<"Eagle is eating..\n";
        }
        void fly() {
            cout<<"Eagle is flying,,\n";
        }
        void speak() {
            cout<<"Eagle is speaking..\n";
        }
};

class Piegon: public Bird {
    public:
        void eat() {
            cout<<"Piegon is eating..\n";
        }
        void fly() {
            cout<<"Piegon is flying,,\n";
        }
        void speak() {
            cout<<"Piegon is speaking..\n";
        }
};


class Dog: public Terrestrial {
    public:
        void  speak() {
            cout<<"Dog is braking..\n";
        }
        void eat() {
            cout<<"Dog is eating..\n";
        }
        void  walk() {
            cout<<"Dog is walking..\n";
        }
};

class Horse: public Terrestrial {
    public:
        void walk() {
            cout<<"Horse is running.\n";
        }
        void speak() {
            cout<<"Horse is speaking..\n";
        }
        void eat() {
            cout<<"Horse is eating chickpeas..\n";
        }

};

#endif 
