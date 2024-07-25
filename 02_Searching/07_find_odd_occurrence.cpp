#include<vector>
#include<iostream>
using namespace std;

int solve(vector<int> arr) {
    int start = 0, end = arr.size()-1, mid;

    while(start <= end) {
        if(start == end) { // single element
            return arr[start];
        }

        mid = start + (end-start)/2;
        if(mid % 2 == 0) {
            // mid is even
            if(arr[mid] == arr[mid+1]) {
                start = mid + 2;
            } else {
                end = mid; 
            }
        }
        else {
            // mid is odd
            if(arr[mid] == arr[mid-1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
 
    vector<int> arr = {1,1,2,2,3,3,4,4,600,4,4,2000,2000};
    cout<<solve(arr)<<endl;

return 0;
}