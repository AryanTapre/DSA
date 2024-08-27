// leetcode 53
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maxSubArrayHelper(vector<int> &nums, int start, int end) {
    if(start >= end) return nums.at(start);
    
    int leftBorderSum = 0, rightBorderSum = 0;
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;

    int mid = start + ((end - start) >> 2);

    int maxLeftSum =  maxSubArrayHelper(nums, start, mid); // FIXME: O(LogN)
    int maxRightSum = maxSubArrayHelper(nums, mid+1, end);

    // calculating left border sum
    for(int i=mid; i>=start; i--) { // O(N)
        leftBorderSum += nums.at(i);
        maxLeftBorderSum = max(leftBorderSum, maxLeftBorderSum);
    }

    // calculating right border sum
    for(int i=mid+1; i<=end; i++) {
        rightBorderSum += nums.at(i);
        maxRightBorderSum = max(rightBorderSum, maxRightBorderSum);
    }

    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

int maxSubArray(vector<int> &nums) { // O(N Log N)
    int start = 0, end = nums.size() - 1;

    return maxSubArrayHelper(nums,start, end);
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<"max sub-array sum is : "<<maxSubArray(nums)<<endl; 
return 0;
}