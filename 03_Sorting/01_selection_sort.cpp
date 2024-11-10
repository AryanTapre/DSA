#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> arr) {
    for(auto i: arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

void selection_sort(vector<int> &arr) {
    int min_index;
    for(int i = 0; i < arr.size()-1; i++) {
        min_index = i;
        // bool isSwapped = false;

        for(int j = i+1; j < arr.size(); j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
                // isSwapped = true;
            }
        }
        
        // if(isSwapped) {
        //     cout<<"Elements are already sorted!.."<<endl;
        //     break;
        // }

        swap(arr[i],arr[min_index]);

        cout<<"round "<<i<<":"<<endl;
        display(arr);
    }
}

int main() {

    vector<int> arr = {1,2,9,10,9};

    cout<<"initial state:"<<endl;
    display(arr);

    selection_sort(arr);

    return 0;
}