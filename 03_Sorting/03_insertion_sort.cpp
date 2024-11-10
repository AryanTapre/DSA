#include<vector>
#include<iostream>
using namespace std;
 
void display(vector<int> arr) {
    for(auto i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

void insertion_sort(vector<int> &arr) {
    int j;
    int set;

    for(int i = 1; i<arr.size(); i++) {
        j = i;
        set = arr[i];
        while(j-1 >= 0 && set < arr[j-1]) {
            j--;
            arr[j+1] = arr[j];
        }

        if(i != j) {
            swap(set,arr[j]);
            display(arr);
        }
    }
}

int main() {
 
    vector<int> arr = {
        1,5,4,8,9,4,2,5,7,9,5,0,10,1,5,7,9,47,12,2,6,5,5,5,5,8,2,0,5,1,2,5,0,5,0,5,0,5,0,5,0,5,0,3,5,1,0,5,4,0,5,4,10,45,78,90,85,40,100,200,10000,56,0,45,10,20,30,45,0,8,0,5,0,5,0,5,0
    };
    cout<<"initial State:"<<endl;
    display(arr);

    insertion_sort(arr);

    cout<<"final"<<endl;
    display(arr);
    
return 0;
}