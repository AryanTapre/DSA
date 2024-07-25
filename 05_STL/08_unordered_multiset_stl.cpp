#include<unordered_set>
#include<iostream>
using namespace std;
 
int main() {
 
    unordered_multiset<int> ml;

    ml.insert(10);
    ml.insert(20);
    ml.insert(30);
    ml.insert(40);
    ml.insert(50);
    ml.insert(10);
    ml.insert(50);


    for(auto i=ml.begin(); i != ml.end(); i++) {
        cout<<*i<<endl;
    }
    
    //TODO: insert(), erase(), find(), size(), empty() is Similar to original Set!.

return 0;
}