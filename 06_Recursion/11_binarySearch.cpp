// implement binary search using recursion

#include<vector>
#include<iostream>
using namespace std;

bool binarySearch(vector<int> &data, int &start, int &end, int &key) {
    if(start > end) return false; //base case

    int mid = start + (end-start) / 2;
    cout<<"start:"<<start<<" "<<"end:"<<end<<" mid:"<<mid<<endl;

    if(data.at(mid) == key) return true;
    else if(data.at(mid) < key) {
        start = mid + 1;
        return binarySearch(data, start, end, key);
    } else {
        end = mid - 1;
        return binarySearch(data, start, end, key);
    }
}

int main() {
    vector<int> data = {20,21,23,49,50,52,58,61,72};
    int start = 0;
    int end = data.size() - 1;
    int key = 50;

    binarySearch(data, start, end,key)? cout<<"key found!"<<endl : cout<<"key does not exists!"<<endl;


return 0;
}