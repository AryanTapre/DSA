#include<unordered_set>
#include<iostream>
using namespace std;

int main() {

    unordered_set<int> s;
    
    s = {50,89,1,20,0,13,4,16};
    
    //Insert
    s.insert(100);
    

    for(auto i=s.begin(); i != s.end(); i++) {
        cout<<*i<<endl;
    }

    //Find
    auto res = s.find(50);
    if(res == s.end()) {
        cout<<"element does not exists"<<endl;
    } else {
        cout<<"element  exists"<<endl;
    }

    //Erase
    auto x = s.erase(13); // Returns an iterater pointing to the next position!.
    cout<<x<<endl;
    cout<<endl<<"after erasing => "<<endl;
    for(auto i=s.begin(); i != s.end(); i++) {
        cout<<*i<<endl;
    }

    cout<<"size:"<<s.size()<<endl;



return 0;
}