//TODO: leetcode 1910
#include<string.h>
#include<iostream>
using namespace std;

string removeOccurrences(string s, string part) {
	while(s.find(part) != string::npos){
		s.erase(s.find(part), part.length());
	}
	return s;
}

int main () {
	string s= "abcabcab";
	string part = "abc";
	cout<<removeOccurrences(s, part)<<endl;
return 0;
}
