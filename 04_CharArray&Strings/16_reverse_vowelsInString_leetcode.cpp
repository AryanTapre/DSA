//leetcode: 345
#include<string.h>
#include<cctype> // for tolower() function
#include<iostream>
using namespace std;
 
bool isVowel(char ch) {
    ch = tolower(ch);
    char vowels[5] = {'a','e','i','o','u'};
    for(auto i : vowels) {
        if(i == ch) return true;
    }
    return false;
}

string reverseVowels(string s) {
    int low = 0;
    int high = s.size()  - 1;
    while(low < high) {

        if(isVowel(s.at(low)) && isVowel(s.at(high))) {
            swap(s[high], s[low]);
            high--;
            low++;
        }
        else if(isVowel(s.at(low)) == 0) {
            low++;
        }
        else {
            high--;
        }
     }
    return s;
}

int main() {
 
    string s = "hello";
    cout<<reverseVowels(s)<<endl;

return 0;
}