#include<iostream>
using namespace std;

class base {
    int x;
    public:
        base(int _x) : x(_x) {
            cout<<"base ctor"<<endl;
        }

        void getX() {
            cout<<this->x<<endl;
        }

        ~base() {
            cout<<"base dtor"<<endl;
        }
};


class derive {`
    int y, *data;
    public:
        derive(int _y) : y(_y) {
            cout<<"derive ctor"<<endl;
        }

        void getY() {
            cout<<this->y<<endl;
        }

        ~derive() {
            cout<<"derive dtor"<<endl;
        }
};

int main() {

    base *b = new derive(10);



return 0;
}