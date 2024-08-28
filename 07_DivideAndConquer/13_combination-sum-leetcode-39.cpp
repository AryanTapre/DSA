// leetcode 39
#include<vector>
#include<iostream>
using namespace std;


    void solve(vector<int>& candidates, int &target, vector<int> &output,vector<vector<int>> &ans, int currentSum, int index) {
        if(currentSum == target) {
            ans.push_back(output);
            return;
        }

        if(currentSum > target) return;

        for(int i=index; i<candidates.size(); i++) {
            output.push_back(candidates[i]);
            solve(candidates, target, output, ans, currentSum+candidates[i],i);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        int currentSum = 0;
        int index = 0;
        solve(candidates,target,output,ans,currentSum, index);
        return ans;
    }

int main() {

    vector<int> a = {2,3,6,7};
    int target = 7;
    
    vector<vector<int> > ans = combinationSum(a, target);

    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    

return 0;
}