#include<utility>
#include<set>
#include<iostream>
using namespace std;
 
int main() {
    
    set<int,greater<int> > val2 = {20,50}; // descending order sorted...
    set<int> val = {7,9,1,5,1,0}; // Ascending order sorted...
    

    //count
    cout<<"is 9 present in set val => "<<val.count(9)<<endl;

    // insert
    val.insert(10);
    val.insert(val2.begin(), val2.end());
    
    set<int>::iterator it = val.begin();

    for(it; it!=val.end(); it++) {
        cout<<*it<<endl;                
    }cout<<endl;

    //find
    auto ite2 = val.begin();
    ite2 = val.find(10);
    if(ite2 != val.end()) {
        cout<<"element found!"<<endl;
    } else {
        cout<<"element not found!"<<endl;
    }

    //erase
    ite2 = val.begin();
    ite2++;
    val.erase(ite2);
    cout<<"after erase =>"<<endl;
    for(it = val.begin(); it!=val.end(); it++) {
        cout<<*it<<endl;                
    }cout<<endl;
    

    val.clear();
    if(val.empty()) {
        cout<<"set is empty!."<<endl;
    }
    else {
        cout<<"Set is not empty!."<<endl;
    } 

    cout<<endl<<"set of pairs=>"<<endl;
    set<pair<int, int> > s_pair = {{1,1},{3,3},{2,2},{1,2},{2,2},{1,1}};
    for(auto i : s_pair) {
        cout<<i.first<<" "<<i.second<<endl;
    }


return 0;
}