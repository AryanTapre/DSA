// leetcode: 49
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
 
map<char,int> generateHashKey(string s) {
    map<char,int> mp;
    
    for(auto i : s) {
        mp[i]++;
    }
    return mp;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    //TODO: method 1
    // map<map<char,int>,vector<string> > mp;
    // vector<vector<string> > ans;

    // for(auto str : strs) {
    //     mp[generateHashKey(str)].push_back(str);
    // }

    // for(auto i : mp) {
    //     ans.push_back(i.second);
    // }
    // return ans;


    //TODO: method 2
    //key is in sorted format

    map<string, vector<string> > nmp;
    vector<vector<string> > ans2;

    for(auto str : strs) {
        string x = str;
        sort(x.begin(), x.end());
        nmp[x].push_back(str);
    }

    for(auto i :nmp) {
        ans2.push_back(i.second);
    }
    return ans2;
    
}

int main() {

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string> > res = groupAnagrams(strs);

    for(auto i : res) {
        for(auto x : i) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

return 0;
}