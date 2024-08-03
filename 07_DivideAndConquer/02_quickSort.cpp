#include<vector>
#include<iostream>
using namespace std;


int getCorrectPivotIndex(int &pivotIndex, int start, int end, vector<int> &arr) {
    int count = 0;
    for(int i=start+1; i<=end; i++) {
        if(arr[i] < arr[pivotIndex]) count++;
    }

    return start + count;
}

int partitionUtility(vector<int> &arr, int start, int end) { // assume arr[start] as pivot always
    int pivot = arr[start];
    int pivotIndex = start;

    int correctPivotIndex = getCorrectPivotIndex(pivotIndex, start, end, arr);
    swap(arr[pivotIndex], arr[correctPivotIndex]);
    pivotIndex = correctPivotIndex;

    int i = start; 
    int j = end;

    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i] < arr[pivotIndex]) {
            i++;
        }
        while(arr[j] > arr[pivotIndex]) {
            j--;
        }

        swap(arr[i], arr[j]);
    }

    return pivotIndex;
}

void quickSortUtility(vector<int> &arr, int start, int end) {
    // basecase
    if(start >= end) return;

    int pivotIndex = partitionUtility(arr, start, end);

    // recursively solving left part of pivot_index
    quickSortUtility(arr, start, pivotIndex-1);
    // recursively solving right part of pivot_index
    quickSortUtility(arr, pivotIndex+1, end);
}

void quickSort(vector<int> &arr) {
    int start = 0;
    int end = arr.size()-1;

    quickSortUtility(arr, start, end);
}

int main() {
    vector<int> arr = {10,9,8,7,6,5,5,5,8,89,45,100,4,3,2,1,0};

    quickSort(arr);

    for(int i : arr) {
        cout<<i<<" ";
    } 
    cout<<endl;
    
return 0;
}