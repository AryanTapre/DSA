//TODO: leetcode 539

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int findMinDifference(vector<string>& timePoints) {
	vector<int> minutes;
	for(auto i: timePoints ) {
		int hour = stoi(i.substr(0,2));
		int min = stoi(i.substr(3,2));
		minutes.push_back(hour*60+min);
	}
	sort(minutes.begin(), minutes.end()); //O(nlogn)
	
	// finding minimun time Difference...
	int mini = INT_MAX;
	for(int i=0; i<minutes.size()-1; i++) {
		int curr = minutes[i+1] - minutes[i];
		mini = min(mini,curr);
	}

	int lastDifference = (minutes[0]+1440) - minutes[minutes.size()-1];
	mini = min(lastDifference, mini);
	return mini;
}

int main() {
	vector<string> timePoints = {"00:00","23:59","01:40"};
	cout<<findMinDifference(timePoints)<<endl;

return 0;
}
