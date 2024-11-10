#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

class abc {
    private:
        int x;

    public:
        static  int data ;
        abc(int _x) : x(_x) {}

        static void update(int d) {
            data = d;
        }

};
int abc::data = 100;
// int abc::data = 100;

int main() {

    abc* a = new abc(10);
    cout<<abc::data<<endl;

    abc::update(20);
    cout<<abc::data<<endl;



    int ax = -1, bx = -2;
    cout<<min(ax,INT_MAX)<<endl;

return 0;
}
