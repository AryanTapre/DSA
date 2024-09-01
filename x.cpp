#include<vector>
#include<iostream>
using namespace std;

int countArrangement(int n) {
        int j = 1;
        vector<int> nums;
        
        for(int i=0; i<n; i++) {
            nums.push_back(j);
            ++j;
        }

        for(int i=0; i<nums.size(); i++) {
            cout<<nums[i]<<" ";
        }
        cout<<endl;

        return 1;
    }

int main() {

    
    countArrangement(5);

return 0;
}