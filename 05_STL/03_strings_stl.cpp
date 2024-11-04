// strings in cpp
#include<string.h>
#include<iostream>
using namespace std;

int main() {
    string data = "Aryan Tapre";
    cout<<"fist char:"<<data.front()<<endl;
    cout<<"last char"<<data.back()<<endl;
    
    data.clear();
    if(data.empty()) {
        cout<<"data is nill"<<endl;
    }
    data = "Aryan Tapre";
    
    data.insert(5,"X",1);
    cout<<"data inserted at postition 5:"<<data<<endl;

    data.erase(data.length()-1,1);
    cout<<"data after erase at last position:"<<data<<endl;

    data.replace(data.length()-2,2,"ZZ");
    cout<<"data replace at last two position:"<<data<<endl;

    char buffer[10];
    int len = data.copy(buffer,4,data.length()-4);
    buffer[len] = '\0';
    cout<<"data copied in buffer[10]: "<<buffer<<endl;

    size_t index = data.find("TaZZ",0);
    if(index != string::npos) {
        cout<<"Tazz found at pos:"<<index<<endl;
    }


    cout<<"sub-string captured:"<<subString<<endl;

    string str1 = "harshad";
    string str2 = "harshad";

    if(str1.compare(str2) == 0) {
        cout<<"strings matched.."<<endl;
    } else {
        cout<<"strings not matched.."<<endl;
    }

    // string str;
    // str = "aryan tapre";

    // cout<<str.front()<<endl;
    // cout<<str.back()<<endl;


    // cout<<"size:"<<str.size()<<endl;
    // cout<<"length:"<<str.length()<<endl;

    // str.clear();

    // str.assign("harshad");    
    // cout<<str<<endl;

    // str.push_back('x');
    // cout<<str<<endl;
    // str.pop_back();
    // cout<<endl<<str<<endl;

    // //insert
    // str.insert(5,"KK",2);
    // cout<<str<<endl;

    // //erase
    // str.erase(5,1);
    // cout<<str<<endl;

    // //replace
    // str.replace(6,5,"harshad");
    // cout<<str<<endl;

    // //Copy
    // char buffer[20];
    // int len = str.copy(buffer,5,0);
    // buffer[len] = '\0';
    // cout<<buffer<<endl;

    // //find
    // size_t index = str.find("aryan",0);
    // cout<<index<<endl;

    // //substr;
    // string subString = str.substr(6,6);
    // cout<<subString<<endl;

    // //compare
    // string s1 = "aryan";
    // string s2 = "harshad";

    // if(s1.compare(s2) == 0) {
    //     cout<<"strings are same"<<endl;
    // } else {
    //     cout<<"Strings are Difference"<<endl;
    // }


return 0;
}