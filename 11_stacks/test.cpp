#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool comp(int A, int B){
    return B < A;  // if expression is true, A will be always first
}



int main() {

    

    vector<int> v = {1,2,3};
    sort(v.begin(), v.end(), comp);

    for(auto i : v) cout<<i<<" ";
    cout<<endl;


return 0;
}