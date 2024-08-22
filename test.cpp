#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


void solve(string &digits, int index,string output, vector<string> &ans,  unordered_map<int,string> &map) {
        if(digits.empty()) {
            return;
        }

        if(index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0';
        string value = map[digit];


        for(int i=0; i<value.size(); i++) {
            char ch = value[i];
            output.push_back(ch);
            solve(digits,index+1,output,ans,map);
            output.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        string output;
        vector<string> ans;
        int index = 0;

        unordered_map<int,string> map;
        map.insert(make_pair(2,"abc"));
        map.insert(make_pair(3,"def"));
        map.insert(make_pair(4,"ghi"));  
        map.insert(make_pair(5,"jkl"));
        map.insert(make_pair(6,"mno"));
        map.insert(make_pair(7,"pqrs"));
        map.insert(make_pair(8,"tuv"));
        map.insert(make_pair(9,"wxyz"));  


        solve(digits,index,output, ans,map);
        return ans;
    }

int main() {

    vector<string> ans = letterCombinations("");
    for(auto i : ans) {
        cout<<i<<endl;
    }

return 0;
}