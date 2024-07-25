#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;

void findMini(vector<int>& a, int& mini, int& i) {
    if(i >= a.size()) return;
    
    a.at(i)<mini? mini = a.at(i): 
    i+= 1;
    findMini(a,mini,i);

}

int main() {
    vector<int> a = {1,2,3,89,100};
    int mini = INT_MAX;
    int i = 0;

    findMini(a,mini,i);
    cout<<mini<<endl;
return 0;
}