// leetcode 47

#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility> // for make_pair() function
using namespace std;

void permuteUniqueHelper(vector<int> &nums, vector<vector<int>> &ans, int index) {
    if(index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> map;
    for(int i=index; i<nums.size(); i++) {
        if(map.find(nums.at(i)) != map.end()) {
            continue;
        }
        map[nums[i]] = true;

        swap(nums.at(index), nums.at(i));
        permuteUniqueHelper(nums,ans, i + 1);
        swap(nums.at(index), nums.at(i)); // backtracking line..
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    int index = 0;

    permuteUniqueHelper(nums,ans,index);
    return ans;
}

int main() {
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans =  permuteUnique(nums);

    for(int i=0; ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


return 0;
}