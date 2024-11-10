// find ith term in fibonacci serirs...

#include<iostream>
using namespace std;

int fib(int n) {
    if(n == 0 || n == 1) return n; //base case..

    int term = fib(n-1) + fib(n-2);
    return term;
}

int main() {

    cout<<"Term is : "<<fib(6)<<endl;

return 0;
}