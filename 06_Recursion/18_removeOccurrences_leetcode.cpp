// Leetcode: 1910

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void removeRE(string &str, string &part) {
    int found = str.find(part);

    if(found != string::npos) {
        string left_string = str.substr(0, found);
        string right_string = str.substr(found+part.size(), str.size());

        str = left_string + right_string;
        removeRE(str, part);

    } else {
        // basecase
        return;
    }
}


string removeOccurrences(string s, string part) {
    removeRE(s,part);
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    cout<<removeOccurrences(s,part);
return 0;   
}