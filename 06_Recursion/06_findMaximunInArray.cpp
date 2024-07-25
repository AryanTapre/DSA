#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;

void findMax(vector<int>& a, int& maxi, int& i) {
    if(i >= a.size()) return;
    
    a.at(i)>maxi? maxi = a.at(i): 
    i+= 1;
    findMax(a,maxi,i);

}

int main() {
    vector<int> a = {1,2,3,89,100};
    int maxi = INT_MIN;
    int i = 0;

    findMax(a,maxi,i);
    cout<<maxi<<endl;
return 0;
}