#include<iostream>
using namespace std;

class abc {
    public:
        int *x;

        abc(int x) {
            this->x = new int(x);
        }

        abc(abc &obj) {
            cout<<"dppe"<<endl;
            this->x = new int(*obj.x);
        }

        void print() {
            cout<<"x value:"<<*x<<endl;
            cout<<"x pointing to:"<<x<<endl;
            cout<<"x address:"<<&x<<endl;
        }

        ~abc() {
            delete this->x;
        }
};

int main() {

   abc a(10);
   abc b = a;

   a.print();
   b.print();

    
    

return 0;
}
