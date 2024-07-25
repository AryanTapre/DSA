// leetcode:28

#include<string>
#include<iostream>
using namespace std;
 
int strStr(string haystack, string needle) {
    //#approach 1
    int index = haystack.find(needle);
    if(index != std::string::npos) {
        return index;
    }
    return -1;


    //# approach 2 - sliding window
    int n = haystack.size();
    int m = needle.size();
    int j;

    for(int i=0; i <= n-m; i++) {
        for(j=0; j<m;j++) {
            if(needle[j] != haystack[i+j]) {
                break;
            }
        }
        if(j == m) {
            return i;
        }
    }
    return -1;

}

int main() {

    string haystack = "sadbutsad";
    string needle = "sad";

    cout<<strStr(haystack,needle)<<endl;

return 0;
}
