#include<iostream>
using namespace std;

void reverse(string &str, int start, int end) {
    if((end-start) < 0) return;
    swap(str.at(start), str.at(end));

    reverse(str,start+1, end-1);
}


int main() {
    string str = "abc"; 

    if(str.at(3)) {
        cout<<"not there..!";
    }

    cout<<str<<endl;
return 0;
}