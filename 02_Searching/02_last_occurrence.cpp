// TODO: find first occurrence of element in sorted array!.

#include<iostream>
#include<vector>
using namespace std;

int last_occurrence(vector<int>& array, int k) {
    int start = 0;
    int end = array.size() - 1;
    int save_index = -1;
    int mid;

    while(start <= end) {
        mid = start + (end-start)/2;

        if(array[mid] == k) {
            save_index = mid;
            start = mid + 1;
        }
        else if(array[mid] < k) {
            start = mid + 1;
        }
        else {
            //array[mid] > k
            end = mid - 1;
        }
    }

    return save_index;
}

int main() {
 
    vector<int> array = {1,2,3,4,5,6,6,7};
    cout<<last_occurrence(array,6);

return 0;
}