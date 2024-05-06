// find a key in given string return true/false..

#include<iostream>
using namespace std;

bool findKey(string &str, int &n, int &i, char &key) {
    if(i >= n)  return false;

    if(str.at(i) == key)  return true;
    i += 1;

    return findKey(str,n,i,key);
}

int main() {
    string str = "honeycomb";
    int i = 0;
    char key = 'a';
    int n = str.size();

    cout<<findKey(str,n,i,key)<<endl;
return 0;
}