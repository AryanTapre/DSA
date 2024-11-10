// Leetcode : 198

#include<iostream>
#include<vector>
using namespace std;


void robHelper(vector<int> &nums, int sum, int &amt, int i) {
    if(i >= nums.size()) {
        if(sum > amt) amt = sum;
        return;
    }

    // include 
    sum += nums[i];
    robHelper(nums, sum, amt, i+2);

    //exclude
    sum -= nums[i];
    robHelper(nums, sum, amt, i+1);
}

int rob(vector<int> &nums) {
    int sum = 0;
    int amt = 0;
    robHelper(nums,sum,amt,0);
    return amt;
}
 
int main() {

    vector<int> nums = {2,1,1,2};

    cout<<"max amount robbed : "<<rob(nums)<<endl;

return 0;
}