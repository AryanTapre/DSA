#include<iostream>
using namespace std;

class Vehicle {
    public:
        Vehicle() {
            cout<<"constructor of Vehicle"<<endl;
        }

        virtual void applyBrakes() = 0;
        virtual void startEngine() = 0;
};

class Magnite: public Vehicle {
    public:
        Magnite() {
            cout<<"constructor of Magnite"<<endl;
        }

        void applyBrakes () {
            cout<<"Magnite applied Brakes.."<<endl;
        }

        void startEngine() {
            cout<<"Magnite engine has been started.."<<endl;
        }
};

class LC3300: public Vehicle {
    public:
        LC3300() {
            cout<<"constructor of LC300"<<endl;
        }

        void applyBrakes () {
            cout<<"LC300 applied Brakes.."<<endl;
        }

        void startEngine() {
            cout<<"LC300 engine has been started.."<<endl;
        }

};

int main() {

    // Magnite mg;
    // mg.applyBrakes();

    
    // upcasting...................
    Vehicle* vehicle;

    vehicle = new Magnite();
    vehicle->applyBrakes();
    vehicle->startEngine();

    cout<<endl;

    vehicle = new LC3300();
    vehicle->applyBrakes();
    vehicle->startEngine();

    
    


return 0;
}