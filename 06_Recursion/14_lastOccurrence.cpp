#include<iostream>
   using namespace std;

int lastOccurrence(string &str, int i, char &key) {
    if(i < 0) return -1;
    if(str.at(i) == key) return i;

    return lastOccurrence(str, i-1, key);
}

int main() {
    string str = "abcfoppf";
    char key = 'x';
    cout<<"last occurrence => "<<lastOccurrence(str, str.size()-1,key);

return 0;
}