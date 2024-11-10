#include<iostream>
#include<algorithm>
using namespace std;

void findPermutation(string &s, int i) {
    // basecase
    if(i >= s.size()) {
        cout<<s<<endl;
        return;
    }

    for(int j=i; j<s.size(); j++) {
        swap(s[i],s[j]);
        findPermutation(s, i+1);
        // backtracking,,'
        swap(s[i],s[j]);
    }
}

int main() {
    string s = "abc";
    int i = 0;

    findPermutation(s,i);
return 0;
}