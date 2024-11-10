// leetcode: 44

#include<iostream>
#include<string>
using namespace std;

bool isMatchHelper(string &p, int pi, string &s, int si) {
    // base-case
    if(si == s.size() && pi == p.size()) return true;

    if(si == s.size() && pi < p.size()) {
        while(pi < p.size()) {
            if(p[pi] != '*') return false;
            pi++; 
        }
        return false;
    }

    // processing single character..
    if(s[si] == p[pi] || p[pi] == '?') {
        return isMatchHelper(p,pi+1, s, si+1);
    }

    if(p[pi] == '*') {
        // treat * as null / empty
        bool caseA = isMatchHelper(p,pi+1, s, si);
        // let * consume one character..
        bool caseB = isMatchHelper(p,pi, s, si+1);
        return caseA || caseB;
    }

    /*  si < s.size() && pi = p.size()  and ,
         s[si] != p[pi]
    */
   return false;
}


bool isMatch(string p, string s) {
    return isMatchHelper(p,0,s,0);
}

int main() {
    string p = "a*aaba***b**a*a********b";
    string s = "abbaaaabbbbbababbbbbbbbaaabaabbabaabbaaabbbbabbbbab";

    cout<<"match result : "<<isMatch(p,s)<<endl;
return 0;
}