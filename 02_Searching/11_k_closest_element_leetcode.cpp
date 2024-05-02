//TODO: leetcode 658: Find K closest elements

#include<vector>
#include<iostream>
using namespace std;

vector<int> get_closest_range(vector<int> &arr, int k, int x) {
    int low = 0;
    int high = arr.size() - 1;

    while(high-low >= k) {
        if(x-arr[low] > arr[high]-x) {
            low++;
        } else {
            high--;
        }
    }
    return vector<int>(arr.begin()+low, arr.begin()+high+1);
}

vector<int> find_closest_element(vector<int> &arr, int k, int x) {
    return get_closest_range(arr,k,x);
}

int main() {
 
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;

    vector<int> ans = find_closest_element(arr,k,x);
    for(auto x : ans) {
        cout<<x<<" ";
    }
    cout<<endl;

return 0;
}