#include<unordered_map>
#include<iostream>
using namespace std;

int main() {
 //TODO: duplcates are not allowed , but it is unordered i.e order is Not maintained!.

    unordered_map<int,string> mp;
    mp = {
            make_pair(1,"one"), 
            make_pair(1,"one"), 
            make_pair(5,"five"),
            make_pair(3,"three"),
            make_pair(4,"four"),
            make_pair(2,"two")
        };

    for(auto i : mp) {
        cout<<i.first<<" "<<i.second<<endl;
    }

return 0;
}