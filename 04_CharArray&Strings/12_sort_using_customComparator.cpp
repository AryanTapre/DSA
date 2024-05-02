//TODO: Implementing a Custom sort() function using custom comparator

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool customComparator(int i, int j) {
	return i > j; // descending order Sorting happend!.	
}

int main() {
	vector<int> arr = {1,2,3,4,5,6,7,8};
	sort(arr.begin(), arr.end(), customComparator);
	vector<int> :: iterator it = arr.begin();

	for(it; it != arr.end(); it++) {
		cout<<*it<<" ";
	}


	return 0;
}
