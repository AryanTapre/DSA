#include<iostream>
#include<string.h>
using namespace std;

string removeDuplicates(string s) {
	string ans = "";
	int i = 0;

	while(i < s.length()) {
		if(ans.empty()) {
			ans.push_back(s[i]);
			i++;
			continue;
		}
		if(ans[ans.length()-1] == s[i]) {
			ans.pop_back();
		} else {
			ans.push_back(s[i]);
		}
		i++;
	}
	return ans;
}

int main() {
	string str = "aaaaaaaa";
	cout<<removeDuplicates(str);
	return 0;
}

