#include<iostream>
#include<vector>
using namespace std;
 
int find_unique(vector<int> &arr) {
    int ans = 0;
    for(auto x: arr) {
        ans = ans ^ x;
    }
    return ans;
}
int main() {
 
    vector<int> data{1,8,3,1,8,3,6,8,6};
    cout<<"Unique element is: "<<find_unique(data);



return 0;
}