// leetcode : 17
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void solve(string &digits, int index, string output, unordered_map<int,string> &map, vector<string> &answer) {
    if(digits.empty()) return;

    if(index >= digits.size()) {
        answer.push_back(output);
        return;
    }

    int digit = digits.at(index) - '0';
    string values = map.at(digit);

    for(int i=0; i<values.size(); i++) {
        output.push_back(values.at(i));
        solve(digits, index+1, output, map, answer);

        // backtracking line..
        output.pop_back();
    }
}

vector<string> letterCombination(string digits) {
    string output;
    vector<string> answer;
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

    solve(digits, index, output, map, answer);
    return answer;  
}

int main() {

    vector<string> ans = letterCombination("23");
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}