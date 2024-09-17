#include<iostream>
using namespace std;

int my_fun() {
    cout<<"hello"<<endl;
    return 0;
}

void _start() {
    int x = my_fun();
    exit(x);
}