#include<iostream>
using namespace std;

int power(int &n) {
    if(n == 1) { // base case..
        return 2;
    }
    int _n = --n;
    return 2 * power(_n);
}

int main() {
    int n = 4;
    cout<<power(n)<<endl;
return 0;
}
