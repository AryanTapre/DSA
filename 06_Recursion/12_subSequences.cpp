// print all the sub-sequences of given String..

#include<iostream>
using namespace std;

void subSequences(string &str, int i, string data) {
    if(i >= str.length()) {
        if(data.empty()) {
            cout<<"empty string"<<endl;
        }
        cout<<data<<endl;
        return;
    }

    // include current character..
    data.push_back(str.at(i));
    subSequences(str, i+1, data);

    // exclude current character..
    data.pop_back();
    subSequences(str, i+1, data);
    
}

int main() {
    string str = "abc";
    subSequences(str, 0, "");
return 0;
}