#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int> &arr, int start, int end) {
    if(start >= end) return;

    int pivot = end;
    int i = start;
    int j = start; // commented

    while(j < pivot) {
        if(arr[j] < arr[pivot]) {
            swap(arr[i], arr[j]); 
            ++i;
        }
        ++j;
    }

    swap(arr[i], arr[pivot]);

    quickSort(arr, start, i-1);
    quickSort(arr, i + 1, end);
}

int main() {
    vector<int> arr = {4,1,3,9,7};

    int start = 0;
    int end = arr.size() - 1; 

    quickSort(arr, start, end);

    for(auto i : arr) cout<<i<<" ";
    cout<<endl;

return 0;
}