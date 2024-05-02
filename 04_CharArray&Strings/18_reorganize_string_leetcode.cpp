//leetcode:767
#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;
 
 string reorganizeString(string s) {
        vector<int> hash(26,0);

        for(int i=0; i<s.size(); i++) {
            hash[s[i] - 'a']++;
        }

        for(auto i : hash) {
            cout<<i<<" ";
        } cout<<endl;

        // finding maximum frequency character..
        char maxFreqChar;
        int maxFreq = INT_MIN;
        for(int i=0; i<hash.size(); i++) {
            if(hash[i] > maxFreq) {
                maxFreq = hash[i];
                maxFreqChar = i + 'a';
            }
        }

        //try placing the maxFreqChar
        int index = 0;
        while(index < s.size() && maxFreq > 0) {
            s[index] = maxFreqChar;
            maxFreq--;
            index += 2;
        }

        if(maxFreq != 0) { // failed to place maxFreqChar...
            return "";
        }

        hash[maxFreqChar - 'a'] = 0;
        
        // placing rest of characters
        for(int i=0; i<hash.size(); i++) {
            while(hash[i] > 0) {
                index = index >= s.size()? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }

int main() {
 
 string s = "xogbmcjjie";
 cout<<reorganizeString(s);

return 0;
}