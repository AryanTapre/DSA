// list is an implementation of singly-linked-list

#include<iostream>
#include<forward_list>
using namespace std;

int main() {

    forward_list<int> li = {1,2,3};
    li.push_front(1000);
    cout<<li.front()<<endl;

    // insert 89 at pos 2
    forward_list<int> ::iterator ite = li.begin();
    li.insert_after(ite,89);
    
    li.erase_after(++ite);

    for(auto it = li.begin(); it != li.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    
    cout<<"is empty: "<<li.empty()<<endl;

    li.remove(89);

    cout<<"after removing 89 : \n";
    for(auto it = li.begin(); it != li.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;


    li.clear();

    cout<<"is empty after li.clear() : "<<li.empty()<<endl;

return 0;
}