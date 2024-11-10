#include<iostream>
using namespace std;

bool isPalindrome(string &str, int start, int end) {
    if((end-start < 0) || (str.size() == 0)) return true;

    if(str[start] != str[end]) return false;

    return isPalindrome(str, start+1, end-1);
}

int main() {
    string input = "";
    cout<<isPalindrome(input, 0, input.size()-1);
return 0;
}