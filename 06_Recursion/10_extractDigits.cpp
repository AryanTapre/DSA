//extract digits from given integer,,

#include<iostream>
using namespace std;

void extractDigits(int &n) {
    if(n == 0) return;

    int digit = n % 10;
    n = n / 10;

    extractDigits(n);
    cout<<digit<<endl;
}

int main() {
    int n = 647;
    extractDigits(n);
return 0;
}