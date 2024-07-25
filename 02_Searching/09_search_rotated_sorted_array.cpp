// search in rotated sorted array

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int find_pivot(vector<int> arr) {
    int start = 0;
    int end = arr.size()-1;
    int mid;

    while(start <= end) {
        if(start == end) {
            return start;
        }
        mid = start + (end-start)/2;

        if(mid+1 <=end && arr[mid] > arr[mid+1]) {
            return mid;
        }
        else if(mid-1 <=start && arr[mid] < arr[mid-1]) {
            return mid-1;
        }

        if(arr[mid] < arr[0]) {
            // right seach space
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return -1;
}

int search(vector<int> &arr, int k) {
    int start,end;
    int pivot_index = find_pivot(arr);
    int ans;

    if(k < arr[0]) {
        ans = binary_search(arr.begin()+pivot_index+1, arr.end(),k);
    }
    else {
        ans = binary_search(arr.begin(),arr.begin()+pivot_index,k);
    }

    return ans;
}

int main() {
 
    vector<int> arr = {9,10,1,2,3,4,5,6};
    cout<<search(arr,18);

return 0;
}