// binary search in Nearly sorted Array

#include<iostream>
using namespace std;
 
int binary_search(int* arr, int k, int n) {
    int start = 0;
    int end = n-1;
    int mid;

    while(start <= end) {
        mid = start + (end-start)/2;

        if(arr[mid] == k)  return mid;
        else if(mid-1>=0 && arr[mid-1] == k) return mid-1;
        else if (mid+1<n && arr[mid+1] == k) return mid+1;

        if(arr[mid] < k) {
            start = mid + 1;
        }
        else {
            end = mid-1;
        }
    }

    return -1;
}

int main() {
 
    int arr[] = {10,3,40,20,50,80,70};
    int n = 7;
    int k = 70;

    cout<<binary_search(arr,k,n); 

return 0;
}