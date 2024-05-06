#include<iostream>
using namespace std;

int power(int &n) {
    if(n == 1) { // base case..
        return 2;
    }
    int _n = --n;
    int smaller = power(_n); // recursive Call for Smaller Problem..
    cout<< "2 * "<<smaller<<endl;
    return 2 * smaller;
}

int main() {
    int n = 4;
    cout<<power(n)<<endl;
return 0;
}
