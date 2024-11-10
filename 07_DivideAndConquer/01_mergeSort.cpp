#include<vector>
#include<iostream>
using namespace std;

void merge(vector<int> &arr, int start, int end) {
    int mid = start + (end - start) / 2;
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    vector<int> left(leftLength);
    vector<int> right(rightLength);

    int k = start;
    for(int i=0; i<leftLength; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for(int i=0; i<rightLength; i++) {
        right[i] = arr[k];
        k++;
    }

    // merge logic...
   int leftIndex = 0;
   int rightIndex = 0;
   int mainIndex = start;

   while(leftIndex< leftLength && rightIndex<rightLength) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
        } else {
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
        }
   }

   // leftArray is not out of bound..
   while(leftIndex < leftLength) {
        arr[mainIndex] = left[leftIndex];
        mainIndex++;
        leftIndex++;
   }

   // rightArray is Not Out Of Bound..
   while(rightIndex < rightLength) {
        arr[mainIndex] = right[rightIndex];
        mainIndex++;
        rightIndex++;
   }

}   

void mergeSort(vector<int> &arr, int start, int end) {
    if(start >= end) return;
    int mid = start + (end - start) / 2;

    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    cout<<"start="<<start<<" "<<"end="<<end<<endl;
    merge(arr, start, end);
}

void sort(vector<int> &arr) {
    int start = 0;
    int end = arr.size() - 1;

    mergeSort(arr, start, end);
}



int main() {

    vector<int> arr = {10,16,24,12,34,12,0,56,100,0};
    sort(arr);

    for(auto x : arr) {
        cout<<x<<" ";
    }

return 0;
}