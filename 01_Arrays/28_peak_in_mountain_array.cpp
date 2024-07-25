#include<vector>    
#include<iostream>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int peak_index;
        int start = 0;
        int end  = arr.size() - 1;
        int mid;

        while(start <= end) {
            mid = (start + end) /2;
                    
            if((mid-1>=0 && mid+1<=arr.size()) && (arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1] )) {
                peak_index = mid;
                    break;
            }
            else if(arr[mid]<arr[mid+1]) {
                    start = mid + 1;
            }
            else if(arr[mid] < arr[mid-1]) {
                end = mid;
            }
        }
        return peak_index;
    }

int main() {
 
    vector<int> arr = {0,1,0};
    cout<<peakIndexInMountainArray(arr);

return 0;
}