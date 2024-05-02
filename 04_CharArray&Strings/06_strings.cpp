// strings in cpp
#include<string.h>
#include<iostream>
using namespace std;
 
int main() {

    string str;
    str = "aryan tapre";

    cout<<str.front()<<endl;
    cout<<str.back()<<endl;


    cout<<"size:"<<str.size()<<endl;
    cout<<"length:"<<str.length()<<endl;

    //str.clear();

    // str.assign("harshad");    
    // cout<<str<<endl;

    str.push_back('x');
    cout<<str<<endl;
    str.pop_back();
    cout<<endl<<str<<endl;

    //insert
    str.insert(5,"KK",2);
    cout<<str<<endl;

    //erase
    str.erase(5,1);
    cout<<str<<endl;

    //replace
    str.replace(6,5,"harshad");
    cout<<str<<endl;

    //Copy
    char buffer[20];
    int len = str.copy(buffer,5,0);
    buffer[len] = '\0';
    cout<<buffer<<endl;

    //find
    size_t index = str.find("aryan",0);
    cout<<index<<endl;

    //substr;
    string subString = str.substr(6,6);
    cout<<subString<<endl;

    //compare
    string s1 = "aryan";
    string s2 = "harshad";

    if(s1.compare(s2) == 0) {
        cout<<"strings are same"<<endl;
    } else {
        cout<<"Strings are Difference"<<endl;
    }

    




return 0;
}