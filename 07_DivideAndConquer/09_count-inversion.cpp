#include<vector>
#include<iostream>
using namespace std;

int merge(vector<int> &arr, int start, int end, int mid) {
    vector<int> left(mid-start+1);
    vector<int> right(end-mid);

    int k  = start;
    for(int i=0; i<left.size(); i++) {
        left[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for(int i=0; i<right.size(); i++) {
        right[i] = arr[k];
        k++;
    }

    int count = 0;

    int i=0;
    int j=0; 
    int maini = start;

    while(i<left.size() && j<right.size()) {
        if(left[i] < right[j]) {
            arr[maini] = left[i];
            i++;
            maini++;
        } else {
            // inversion count case left[i] > right[j]
            count += mid-i + 1;
            arr[maini] = right[j];
            j++;
            maini;
        }
    }

    // left is still remaining and right get finished..
    while(i<left.size()) {
        arr[maini] = left[i];
        i++;
        maini++;
    }

    while(j<right.size()) {
        arr[maini] = right[j];
        j++;
        maini++;
    }

    return count;
}

int mergeSort(vector<int> &arr , int start, int end) {
    if(start >= end) return 0;

    int mid = start + (end - start) / 2;
    int count = 0;
    // left part
    count += mergeSort(arr,start, mid);
    // right part
    count += mergeSort(arr,mid+1, end);

    // merge logic
    count += merge(arr,start, end, mid);
    return count;
}

int countInversions(vector<int> &arr) {
    int start = 0;
    int end = arr.size()-1;
    return mergeSort(arr, start, end);
}

int main() {

    vector<int> arr = {2,4,1};
    int count = countInversions(arr);
    cout<<"count inversion is : "<<count<<endl;
return 0;
}