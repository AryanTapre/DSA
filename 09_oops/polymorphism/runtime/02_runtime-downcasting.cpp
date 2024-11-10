#include<iostream>
using namespace std;

class Vehicle {
    public:
        Vehicle() {
            cout<<"constructor of Vehicle"<<endl;
        }

        void applyBrakes() {
            cout<<"vehicle applied brakes"<<endl;
        }
        void startEngine() {
            cout<<"vehicle engine started"<<endl;
        }
};

class Fortuner: public Vehicle {
    public:
        Fortuner() {
            cout<<"constructor of Fortuner called"<<endl;
        }
        void applyBrakes() {
            cout<<"Fortuner applied brakes"<<endl;
        }

        void startEngine() {
            cout<<"Fortuner engine started"<<endl;
        }

        void engage4by4() {
            cout<<"enabled 4 * 4 "<<endl;
        }
};

int main() {

    Fortuner* fortuner;
    
    fortuner = static_cast<Fortuner*>(new Vehicle);
    fortuner->engage4by4();
    


return 0;
}
