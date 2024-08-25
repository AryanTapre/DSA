#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


void merge(vector<int> &arr, int start, int end, int mid) {
    int i = start;
    int j = mid + 1;

    while(i<=mid && j<=end) {
        if(arr[i] < arr[j]) {
            i++;
        }
        swap(arr[i],arr[j]);
        i++;
        j++;
    }
}

void mergeSort(vector<int> &arr, int start, int end) {
    if(start >= end) return;

    int mid = start + (end-start) / 2;

    //left
    mergeSort(arr,start,mid);
    // right;
    mergeSort(arr,mid+1,end);

    merge(arr,start,end,mid);
}

int main() {

vector<int> arr = {5,8,10,0,45,8,9,6};
mergeSort(arr,0,arr.size()-1);

for(auto i:arr) cout<<i<<" ";
cout<<endl;

return 0;
}