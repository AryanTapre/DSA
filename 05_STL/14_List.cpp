// list is an implementation of doubly-linked-list
// stores data/elements in non-contgious manner, but accessed in sequential fashion / linear mannner

#include<iostream>
#include<list> // doubly linked list
using namespace std;

int main() {

    /* functions/methods of list class
        @front() 
        @back()
        @push_front()
        @push_back()
        @pop_front()
        @pop_back()
        @list::begin()
        @list::end()
        @empty()
        @insert()
        @erase()
        @assign()
        @clear()
    */
    
    list<int> li;
    li.push_front(20);
    li.push_front(10);
    li.push_back(100);

    cout<<"front element: "<<li.front()<<endl;
    cout<<"back element: "<<li.back()<<endl;


    li.insert(li.begin(),1, 500);

    cout<<"front element: "<<li.front()<<endl;

    cout<<"is empty: "<<li.empty()<<endl;

    li.erase(li.begin());

    cout<<"front element after erasing li.begin(): "<<li.front()<<endl;    


    cout<<"printing list => \n";
    list<int>::iterator ite = li.begin();
    for(ite; ite!=li.end(); ite++) {
        cout<<*ite<<" ";
    }   
    cout<<endl;

    li.clear();
    cout<<"is empty after li.clear() : "<<li.empty() << endl; 


return 0;
}