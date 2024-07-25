#include<iostream>
using namespace std;

int climb(int n) {
    if(n == 0 || n == 1) return 1;

    int a = climb(n-1);
    int b = climb(n-2);
    
    return (a + b) ; 
}

int main() {

    cout<<climb(3)<<endl;

return 0;
}