#include<array>
#include<utility>
#include<iostream>
using namespace std;

int main() {

    pair<int,string> name(1,"aryan");
    cout<<name.first<<" "<<name.second<<endl;

    pair<string,string> city;
    city = make_pair("Surat","Jaipur");
    

    pair<double,double> price = {94.5,90.20};

    pair<int, int> hi;
    cout<<hi.first<<" "<<hi.second<<endl; // TODO: Default initialization to 0


    // declaring array of pairs
    array<pair<int,int>,5 > arr;
    arr.fill(make_pair(1,0));
    for(auto i:arr) {
        cout<<i.first<<" "<<i.second<<endl;
    }


    
return 0;
}