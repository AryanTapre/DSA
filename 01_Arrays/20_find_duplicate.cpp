// leetcode: 287
// Find the Duplicate number

#include<vector>
#include<iostream>
using namespace std;
 
int find_duplicate(vector<int>& nums) {
    vector<int> temp(nums.size(),0);
    int res;
    for(int i = 0; i < nums.size(); i++) {
        temp[nums[i]]++;
    }

    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] > 1) {
            res = i;
            break;
        }
    }
    return res;
}

int main() {
 
    vector<int> nums = {1,3,1,5,2};
    cout<<find_duplicate(nums);

return 0;
}