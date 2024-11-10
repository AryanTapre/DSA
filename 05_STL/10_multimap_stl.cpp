#include<utility>
#include<map>
#include<iostream>
using namespace std;
 
int main() {
    //TODO: everything is same like regular map, except multimap allowed duplicate keys

    multimap<int,string> ascen;
    
    ascen.insert(pair<int,string>(1,"one"));
    ascen.insert({2,"two"});
    ascen.insert({4,"four"});
    ascen.insert({3,"three"});
    ascen.insert({3,"three"});

    for(auto i : ascen) {
        cout<<i.first<<"->"<<i.second<<endl;
    }

    // Erase duplicate
    auto res = ascen.find(3);
    ascen.erase(res);
    cout<<"after erase =>"<<endl;
    for(auto i : ascen) {
        cout<<i.first<<"->"<<i.second<<endl;
    }


    // goal is to remove all duplicates elements from a multi-map
    multimap<int,int> mp = {{1,1},{2,3},{10,10},{2,3},{8,8},{1,1}};
    multimap<int,int> dup; 

    for(auto i : mp) {
        auto res = dup.find(i.first); 
        if(res == dup.end()) {
            dup.insert(make_pair(i.first,i.second));
        }
        else {
            mp.erase(res);
        }
    }

    cout<<endl<<"goal ->"<<endl;
    for(auto i : mp) {
        cout<<i.first<<"->"<<i.second<<endl;
    }


return 0;
}