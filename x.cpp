#include<unordered_map>
#include<iostream>
using namespace std;

int main() {

    unordered_map<int, int> map;
    map[2] = 1;
    map[3] = 1;

    if(!map[2] ) {
        cout<<"true";
    } else {
        cout<<"false";
    }
    cout<<endl;

return 0;
}