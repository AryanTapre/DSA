#include<vector>
#include<iostream>
using namespace std;
 
int main() {
 
    vector<int> data = {10,20,30,40,70,50};
    int target = 80;
    for(int i = 0; i < data.size(); i++) {
        for(int j = i+1; j < data.size(); j++) {
            if(data[i] + data[j] == target) {
                cout<<"pair: ("<<data[i]<<","<<data[j]<<")"<<endl;
            }
        }
    }   

return 0;
}