#include<vector>
#include<iostream>
using namespace std;

void display(vector<int> arr) {
    for(auto i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

void bubble_sort(vector<int> &arr) {
    for(int i = 0; i < arr.size()-1; i++) {

        for(int j = 0; j<arr.size()-1-i;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main() {
 

    vector<int> arr = {5,4,3,2,1,45,89,5,12,0,10};
    bubble_sort(arr);
    display(arr);

return 0;
}