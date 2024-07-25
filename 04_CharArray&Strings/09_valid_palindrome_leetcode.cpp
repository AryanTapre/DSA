//TODO: LeetCode 680
#include<iostream>
#include<string.h>
using namespace std;

bool isPalin(string s, int i, int j) {
    while(i <= j) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    int i = 0;
    int j = s.length()-1;

    while(i <= j) {
        if(s[i] != s[j]) {
            return isPalin(s, i+1, j) || isPalin(s, i, j-1);
        }
        i++;
        j--;
    }
    return true;
}

int main() {
 string s("maxdamp");
 cout<<validPalindrome(s)<<endl;

return 0;
}