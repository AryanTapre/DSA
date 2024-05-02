#include<string.h>
#include<iostream>
using namespace std;
 
int main() {
 
    char name[100];
    cout<<"enter your name :"<<endl;
    // cin>>name;
    cin.getline(name,100);

    cout<<endl<<name<<endl;

    cout<<endl<<"Storage allocation =>"<<endl;
    for(int i=0; i<20; i++) {
        cout<<"name["<<i<<"] = "<<name[i]<<endl;
    }   

    cout<<"null character = "<<(int)name[11]<<endl;
return 0;
}