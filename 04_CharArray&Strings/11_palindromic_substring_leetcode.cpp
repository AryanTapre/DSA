//TODO: leetcode 647
#include<iostream>
#include<string.h>
using namespace std;

void expandSubstring(string s, int i, int j, int &count) {
	while(i>=0 && j<s.length() && s[i] == s[j]) {
		count++;
		i--;
		j++;
	}
}

int countSubstring(string s) {
	int count = 0;
	for(int i=0; i<s.length(); i++) {
		// odd length
		expandSubstring(s,i,i,count);
		//even lenght
		expandSubstring(s,i,i+1,count);
	}
	return count;
}

int main() {

	string str = "aaa";
	cout<<countSubstring(str)<<endl;

return 0;
}
