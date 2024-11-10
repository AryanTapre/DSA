#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

// willing the mouse wheel

void solve(vector<int> &a, int target, vector<int> output,vector<vector<int>> &ans, int currentSum, unordered_map<int,int> &map) {
    if(currentSum == target) {
        bool flag = false;
        for(int i=0; i<output.size(); i++) {
            if(!map[output[i]]) {
                map[output[i]] = 1;
                flag = true;
            }
        }

        if(flag == true) ans.push_back(output);
        return;
    }

    if(currentSum > target) return;

    for(int i=0; i<a.size(); i++) {
        output.push_back(a[i]);
        solve(a, target,output,ans, currentSum + a[i],map);
        output.pop_back();
    }
}

int main() {
    unordered_map<int,int> map;
    vector<int> a = {2};
    int target = 1;
    vector<int> output;
    vector<vector<int >> ans;
    int currentSum = 0;

    solve(a, target, output,ans, currentSum,map);

    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

return 0;
}