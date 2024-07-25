#include<iostream>
using namespace std;

void reverse(string &str, int start, int end) {
    if((end-start) < 0) return;
    swap(str.at(start), str.at(end));

    reverse(str,start+1, end-1);
}

int main() {
    string str = "abc";
    reverse(str,0,str.size()-1);
    cout<<str<<endl;
return 0;
}