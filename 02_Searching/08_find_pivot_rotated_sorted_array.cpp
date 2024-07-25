// TODO: find an pivot element on Rotated and sorted array
// pivot element = largest element in array

#include<vector>
#include<iostream>
using namespace std;
 
int find_pivot(vector<int> arr) {
    int start = 0;
    int end = arr.size()-1;
    int mid;

    while(start <= end) {
        if(start == end) {
            return arr[start];
        }

        mid = start + (end-start) / 2;
        if(mid+1 <= end && arr[mid] > arr[mid+1]) {
            return arr[mid];
        }
        else if(mid-1 <= start && arr[mid] < arr[mid-1]) {
            return arr[mid-1];
        }

        // conditions for moving left and right Search space...
        if(arr[mid] < arr[0]) {
            // standing on left search space and move to Right search space..
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return -1;
}

int main() {
 
    vector<int> arr = {9,10,1,2,3,4,5};
    cout<<find_pivot(arr)<<endl;

return 0;
}