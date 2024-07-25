// leetcode : 6
#include<iostream>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
   if(numRows == 1) return s;

        vector<string> zigzag(numRows);
        int row = 0, i = 0;
        bool direction = 1;

        while(true) {
            if(direction) {
                while(row < numRows && i < s.size()) {
                    zigzag[row++].push_back(s[i++]);
                }
                row = numRows - 2;
            }
            else {
                while(row >=0 && i < s.size()) {
                    zigzag[row--].push_back(s[i++]);
                }
                row = 1;
            }
            if(i >= s.size()) break;
            direction = !direction;
        }

        string ans = "";
        for(auto i : zigzag) {
            ans.append(i);
        }
        return ans;

}

int main() {

    string  str = "abcde";
    int rows = 2;
    cout<<convert(str,rows)<<endl;

return 0;
}