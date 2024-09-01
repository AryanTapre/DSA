// leetcode 1655
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool canDistributeHelper(vector<int> &counts, int customer, vector<int> &quantity) {
    if(customer >= quantity.size()) return true;

    for(int i=0; i<counts.size(); i++) {
        if(counts[i] >= quantity[customer]) {
            counts[i] -= quantity[customer];

            bool isDistributed = canDistributeHelper(counts, customer + 1, quantity);
            if(isDistributed) return true;

            counts[i] += quantity[customer]; // backtracking..

        }
    }
    return false;
}

bool canDistribute(vector<int> &nums, vector<int> &quantity) {
    unordered_map<int,int> freqCount;
    for(auto i : nums) 
        freqCount[i]++;
    
    vector<int> counts;
    for(auto i: freqCount) 
        counts.push_back(i.second);

    int customer = 0;
    sort(quantity.rbegin(), quantity.rend());

    return canDistributeHelper(counts,customer,quantity);
}

int main() {
    vector<int> nums = {1,1,2,2,3,3,3};
    vector<int> quantity = {2,2,3};

    cout<<canDistribute(nums, quantity)<<endl;

return 0;
}