// leetcode: 205

#include<string.h>
#include<iostream>
using namespace std;
 
bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    char hash[256] = {0}; // handles mapping of characters of string s.
    char thash[256] = {0}; // handles whether character of string t is mapped with character of string s.

    for(int i=0; i<s.size(); i++) {
        if(hash[s[i]] == 0 && thash[t[i]] == 0) {
            hash[s[i]] = t[i];
            thash[t[i]] = true;
        }
    }

    for(int i=0; i<s.size(); i++) {
        if(hash[s[i]] != t[i]) {
            return false;
        }
    }
    return true;
}

int main() {
 
    string s = "paper";
    string t = "title";

    cout<<"is isomorphic status:"<<isIsomorphic(s,t);

return 0;
}