// TODO: Multi-Set will contain multiple same values i.e duplicate values are allowed here but in sorted order!.
#include<set>
#include<iostream>
using namespace std;

int main() {
    multiset<int> s; // ascending order multi-set..
    multiset<int,greater<int> > d; // descedning order multi-set..

    s.insert(10);  /* 2 4 10 10 15  */
    s.insert(2);
    s.insert(10);
    s.insert(15);
    s.insert(4);

    cout<<"count :"<<s.count(6)<<endl;

    for(auto i = s.begin(); i != s.end(); i++) {
        cout<<*i<<endl;
    }

    s.erase(10);
    
    cout<<"after erase 10 =>"<<endl;
    for(auto i = s.begin(); i != s.end(); i++) {
        cout<<*i<<endl;
    }


return 0;
}