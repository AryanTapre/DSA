#include<vector>
#include<iostream>
using namespace std;
 
int main() {
 
    vector<int> data = {0,1,1,0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,1,0,0};
    int start = 0;
    int end = data.size() - 1;

    // front will add Zero
    // Rear will add One
    // int i = 0;
    // while(i != end) {
    //     if(data[i] == 0) {
    //         swap(data[start],data[i]);
    //         start++;
    //         i++;
    //     }
    //     else if(data[i] == 1) {
    //         swap(data[end],data[i]);
    //         end--;
    //     }
    // }

    while(start < end) {
        while(data[start] != 1) {
            start++;
        }
        while(data[end] != 0) {
            end--;
        }

        if(start < end)
            swap(data[start],data[end]);

        for(auto x : data) {
            cout<<x<<" ";
        } cout<<endl;
    }

    cout<<endl<<endl;
    for(auto x : data) {
        cout<<x<<" "; 
    }


return 0;
}