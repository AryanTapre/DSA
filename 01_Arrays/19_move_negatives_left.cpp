// move all Negatives values towards left, Order does not matter!.
#include<vector>
#include<iostream>
using namespace std;
 
void move_negatives_left(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {
        while(arr[start] < 0) {
            start++;
        }
        while(arr[end] > 0) {
            end--;
        }

        if(start < end) {
            swap(arr[start],arr[end]);
        }
    }
}

int main() {
 
    vector<int> arr = {-1,2,-3,56,5,5,5,10,-45,-2,-3};
    move_negatives_left(arr);

    for(auto x : arr) {
        cout<<x<<" ";
    }

return 0;
}