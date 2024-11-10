// leetcode:5
#include<string>
#include<utility>
#include<iostream>
using namespace std;

 bool isPalindrome(string& s, int start, int end) {
        bool isValid = true;
        while(start < end) {
            if(s[start] != s[end]) {
                isValid = false;
                break;
            }
            start++;
            end--;
        }
        return isValid;
    }

    void expandString(string& s, int i, int j,  pair<int,string>& palindrome) {
        
        while(i<s.size() && j<s.size()) {
            if(isPalindrome(s,i,j)) {
                int dis = (j-i) + 1;
                if(dis >= palindrome.first ) {
                    palindrome = make_pair(dis,s.substr(i, j-i+1));
                }           
            }
            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {
        string ans = "";
        pair<int,string> palindrome;
        for(int i=0; i<s.size(); i++) {
            //even
            expandString(s,i,i+1,palindrome);
            //odd
            expandString(s,i,i,palindrome);
        }
        ans = palindrome.second;
        return ans;
    }

int main() {
 
    string str = "abcd";
    cout<<longestPalindrome(str)<<endl;

return 0;
}