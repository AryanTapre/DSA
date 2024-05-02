//TODO: binary search in 2D array

#include<vector>
#include<iostream>
using namespace std;
 
bool binary_search(vector<vector<int> > arr, int k, int n, int m) {
    int start = 0;
    int end = (n*m) - 1;
    int mid;

    while(start <= end) {
        mid = start + (end-start) / 2;
        int i = mid / m;
        //int j = mid % m;

        // another way: C * i + j = mid
        int left = m * i;
        int j = mid - left;

        if(arr[i][j] == k) {
            return true;
        }
        else if (arr[i][j] < k) {
            start = mid + 1;

        }
        else {
            end = mid - 1;
        }
    }
    return false;

}

int main() {
 
    vector<vector<int> > arr(4,vector<int>(3));
    arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };

    // n = row
    // m = columns
    int n = 4, m = 3;

    if(binary_search(arr,1,n,m)) {
        cout<<"present"<<endl;
    } else {
        cout<<"Absent"<<endl;
    }


return 0;
}