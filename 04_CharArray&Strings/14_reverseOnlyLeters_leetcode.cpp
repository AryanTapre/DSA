// leetcode : 917

#include<iostream>
using namespace std;

bool isAlphabet(char ch) {
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
        return true;
    }
    return false;
}

string reverseOnlyLetters(string &s) {
    int start = 0;
    int end = s.size() - 1;

    while(start <= end) {
        if(!isAlphabet(s[start])) {
            start++;
        } else if(!isAlphabet(s[end])) {
            end--;
        } else {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    return s;
}

int main() {

    string s = "leetcode-";
    cout<<reverseOnlyLetters(s)<<endl;

return 0;
}