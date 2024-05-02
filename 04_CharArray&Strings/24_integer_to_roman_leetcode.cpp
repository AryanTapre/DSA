// leetcode : 12
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

 string intToRoman(int num) {
         map<int, string, greater<int> > mp = {
            make_pair(1,"I"),
            make_pair(4,"IV"),
            make_pair(5,"V"),
            make_pair(9,"IX"),
            make_pair(10,"X"),
            make_pair(40,"XL"),
            make_pair(50,"L"),
            make_pair(90,"XC"),
            make_pair(100,"C"),
            make_pair(400,"CD"),
            make_pair(500,"D"),
            make_pair(900,"CM"),
            make_pair(1000,"M")
        };

        
        string ans = "";
        
        while(num > 0) {
            auto it = mp.begin();
            for(it = mp.begin(); it!=mp.end(); it++) {
                if(it->first <= num) {
                    break;
                }
            }            
            num -= it->first;
            ans.append(it->second);
        }
        return ans;
      
    }

int main() {

    int num = 58;
    cout<<intToRoman(num)<<endl;


return 0;
}