#include<vector>
#include<iostream>
using namespace std;
 
int main() {
 
    vector<int> v = {0,0,1,0,1,2,0,2,0,1,0};
    int i = 0;
    int start = 0;
    int end = v.size()-1;

    while(i <= end) {
        if(v[i] == 0) {
            swap(v[i],v[start]);
            start++;
            i++;
        }
        else if(v[i] == 2) {
            swap(v[i],v[end]);
            end--;
        }
        else  {
            i++;
        }
    }

    for(auto i : v) {
        cout<<i<< " ";
    }

return 0;
}