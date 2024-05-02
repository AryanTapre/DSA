#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
 
int main() {
 
    vector<int>v = {1,2,5,4,3,3,50};
    cout<<"size of v =>"<<v.size()<<endl;



    cout<<"occurrence of 1 in v => "<<count(v.begin(), v.end(),1)<<endl;
    vector<int>::iterator it = find(v.begin(), v.end(), 3);
    
    // for(auto it = v.begin(); it!=v.end(); it++) {
    //     cout<<*it<<endl;
    // }

    // sort(v.begin(), v.end(), greater<int>());
    // for(auto it = v.begin(); it!=v.end(); it++) {
    //     cout<<*it<<endl;
    // }     


    // Understanding `lower_bound` and `upper_bound` => 
    auto ite = lower_bound(v.begin(), v.end(), 3);
    auto ite2 = upper_bound(v.begin(), v.end(), 3);
    cout<<"lower_bound of 3"<<ite-v.begin()<<endl;
    cout<<"upper_bound of 3"<<ite2-v.begin()<<endl;

    //FIXME:
    //deleting duplicates in vector...
    v.erase(unique(v.begin(), v.end()), v.end());
    
    cout<<endl;
    for(auto i : v) {
        cout<<i<<" ";
    }
    

    cout<<endl<<"distance => "<<endl;
    cout<<distance(v.begin(),v.end());

return 0;
}