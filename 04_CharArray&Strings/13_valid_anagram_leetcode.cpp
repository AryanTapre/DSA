// leetcode : 242

#include<iostream>
#include<string.h>
using namespace std;

bool isAnagram(string s, string t) {
    int freqTable[256] = {0};

    for(int i=0; i<s.size(); i++) { // O(n)
        freqTable[s[i]]++;
    }
    for(int i=0; i<t.size(); i++) { //O(m)
        freqTable[s[i]]--;
    }

    for(int i=0; i<256; i++) {
        if(freqTable[i] != 0) {
            return false;
        }
    }
    return true;        
}

int main() {

    string s = "anagram";
    string t = "anagram";

    cout<<isAnagram(s,t)<<endl;

return 0;
}

