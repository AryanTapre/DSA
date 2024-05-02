//TODO: find missing is sorted array of size N integers from 1 to N;

#include<iostream>
using namespace std;

int find_missing(int* array, int n) {
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end) {
        mid = start + (end-start) / 2;

        // missing found!
        if(array[mid] != mid + 1 && array[mid-1] == mid) {
           return mid + 1; 
        }

        // search left space
        if(array[mid] != mid + 1) {
            end = mid - 1;
        }
        else {
            // Search right Space
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
 
    int array[] = {1,3,4,5,6,7,8,9,10,11};
    int n = 10;

    cout<<"missing element is : "<<find_missing(array,n);

return 0;
}