#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& a, int& i) {
    if(i >= a.size()) {
        return;
    }
    cout<<a.at(i)<<endl;
    i+=1;
    print(a,i);
  
}

int main() {
    vector<int> a = {1,2,3,4,5,6};
    int i = 0;
    print(a,i);
return 0;
}