#include<vector>
#include<iostream>
using namespace std;
 
int main() {
 
    vector<int> arr(2,-1); // initializing vector with 2 size and fill be -1 default vals..
    for(auto x: arr) {
        cout<<x<<" ";
    }

    arr.insert(arr.begin(),100);
    arr.push_back(1000);
    arr.pop_back();

    for(auto x: arr) {
        cout<<x<<" ";
    }cout<<endl;

    cout<<"Capacity:"<<arr.capacity()<<endl;
    cout<<"Size:"<<arr.size()<<endl;

    arr.erase(arr.begin());
     for(auto x: arr) {
        cout<<x<<" ";
    }cout<<endl;


    vector<int>:: iterator it;
    it = arr.begin();

    for(it; it != arr.end(); it++) {
        cout<<*it<<" ";
    } cout<<endl;

    if(arr.empty()) {
        cout<<"vector is empty!"<<endl;
    } else {
        cout<<"vector is not empty!"<<endl;
    }

return 0;
}