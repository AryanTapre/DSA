#include<iostream>
#include<stack>
using namespace std;

int main() {

    stack<int> s;

    cout<<"empty:"<<s.empty()<<endl;

    //push
    s.push(50);
    s.push(21);
    cout<<"Size: "<<s.size()<<endl;
    cout<<"top:"<<s.top()<<endl;

    // pop
    s.pop();
    cout<<"top after pop:"<<s.top()<<endl;
    s.pop();
    
    cout<<"is empty: "<<s.empty()<<endl;



    s.push(10);    
    s.push(20);    
    s.push(30);    
    s.push(40);    
    s.push(50);    
    s.push(60);    

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

return 0;
} 