#include<vector>
#include<iostream>
using namespace std;
 
int main() {
 
    vector<vector<int> > arr(3,vector<int>(3));
    arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int row = arr.size();
    int col = arr[0].size();

    for(int i = 0; i < col; i++) {
        // even- top to bottom
        if((i & 1) == 0) {
            for(int j = 0; j < row; j++) {
                cout<<arr[j][i]<<" ";
            }
        }
        else  {
            // odd
            for(int j = row-1; j >= 0; j--) {
                cout<<arr[j][i]<<" ";
            }
        }
    }

return 0;
}