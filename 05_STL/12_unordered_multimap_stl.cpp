#include<unordered_map>
#include<iostream>
using namespace std;

int main() {

//TODO: Order is not maintained, allowing duplicate keys!.

    unordered_multimap<int,string> ump;
    
    ump.insert(make_pair(2,"two"));
    ump.insert(make_pair(1,"one"));
    ump.insert(make_pair(1,"one"));
    ump.insert(make_pair(10,"ten"));
    ump.insert(make_pair(1,"one"));
    ump.insert(make_pair(10,"ten"));

    for(auto i : ump) {
        cout<<i.first<<" "<<i.second<<endl;
    }

return 0;
}