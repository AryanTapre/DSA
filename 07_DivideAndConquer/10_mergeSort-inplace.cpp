// leetcode: 912
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void merge(vector<int> &arr, int start, int end, int mid) {
    int total_length = end - start + 1;
    int gap = ceil(total_length / 2);

    while(gap > 0) {
        int i = start, j = start + gap;
        while(j <= end) {
            if(arr[i] > arr[j]) swap(arr[i], arr[j]);
            ++i,++j;
        }

        // update gap..
        gap = gap/2 == 0 ? 0 : ceil(gap/2);
    }
}

void mergeSort(vector<int>&arr, int start, int end ) {
    if(start >= end) return;
    int mid = (start+end) >> 1;
    //left call
    mergeSort(arr,start,mid);
    //right call
    mergeSort(arr,mid+1,end);

    merge(arr,start,end,mid);
}

int main() {
    vector<int> a = {5,1,1,2,0,0};
    mergeSort(a,0,a.size()-1);

    for(auto i : a) cout<<i<<" ";
    cout<<endl;
return 0;
}