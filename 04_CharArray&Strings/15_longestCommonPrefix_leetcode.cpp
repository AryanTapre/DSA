//leetcode:14
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

string longestCommmonPrefix(vector<string> &strs) {
    char curr_char = 0;
    int i = 0;
    string ans = "";

    while(true) {
        for(auto str : strs) {
            if(i >= str.size()) {
                curr_char = 0;
                break;
            }
            if(curr_char == 0) {
                curr_char = str[i];
            } 
            else if(curr_char != str[i]) {
                curr_char = 0;
                break;
            }
        }
        if(curr_char == 0) {
            break;
        } 
        ans.push_back(curr_char);
        i++;
        curr_char = 0;
    }
    return ans;
}

int main() {

    vector<string> str = {"flower","flow","floght"};
    cout<<longestCommmonPrefix(str)<<endl;
    
return 0;
}