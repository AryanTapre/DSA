#include<map> // unique key elements and in sorted order either in Ascending or Descedning order!.
#include<utility>
#include<iostream>
using namespace std;

int main() {

    map<int,string> ascending_order_map; // ascending order pair!.


    //Insert
    ascending_order_map.insert(make_pair(1,"One"));
    ascending_order_map.insert(make_pair(2,"Two"));
    ascending_order_map.insert(make_pair(4,"Four"));
    ascending_order_map.insert(make_pair(5,"Five"));
    ascending_order_map.insert(make_pair(3,"Three"));
    ascending_order_map.insert(make_pair(5,"six"));

    
    for(auto i : ascending_order_map) {
        cout<<i.first<<"=>"<<i.second<<endl;
    }

    // element present or not?
    cout<<"is 4 present in map? : "<<ascending_order_map.count(4)<<endl;

    //find
    map<int,string>::iterator ite;
    ite = ascending_order_map.find(2);
    if(ite == ascending_order_map.end()) {
        cout<<"element not found!"<<endl;
    } else {
        cout<<"element Found!"<<endl;
    }

    //erase
    auto res = ascending_order_map.erase(1);
    cout<<"After erase =>"<<endl;
    for(auto i : ascending_order_map) {
        cout<<i.first<<"=>"<<i.second<<endl;
    }

    ascending_order_map.clear();
    cout<<"is empty?"<<ascending_order_map.empty()<<endl;

    

    map<int,int,greater<int> > descending_order_map = {make_pair(1,1),make_pair(2,2),make_pair(3,3)};
    for(auto i : descending_order_map) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    
return 0;
}
