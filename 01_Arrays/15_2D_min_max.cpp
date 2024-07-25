#include<iostream>
#include<limits.h>
using namespace std;

int main() {
    
    int arr[][3] = {
        {8,101,300},
        {0,9,100},
        {42,35,15}
    };

    int rows = 3, cols = 3;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    
    for (size_t i = 0; i < cols; i++) {
        for (size_t j = 0; j < rows; j++) {
            if(arr[j][i] > maxi) {
                maxi = arr[j][i];
            }
            if(arr[j][i] < mini) {
                mini = arr[j][i];
            }
        }   
    }
    
    cout<<"maximum element is :" <<maxi<<endl;
    cout<<"minmum element is :"<<mini<<endl;

return 0;
}