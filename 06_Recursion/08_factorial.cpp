#include<iostream>
using namespace std;

int fact(int& n) {
    if(n == 1) return 2;
    
    n-= 1;
    return 2 * fact(n);
}

int main() {
    int n = 5;
    cout<<fact(n)<<endl;
return 0;
}