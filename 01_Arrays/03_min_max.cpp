#include<limits.h>
#include<iostream>
using namespace std;

void getMaximum(int *array,int size, int &maxi) {
    for(int i=0; i<size; i++) {
        if(array[i] > maxi) {
            maxi = array[i];
        }
    }
}
void getMinimun(int *array,int size, int &mini) {
    for(int i=0; i<size; i++) {
        if(array[i] < mini) {
            mini = array[i];
        }
    }
}

int main() {

    int array[] = {2,1,8,4,9};
    const int size = sizeof(array)/sizeof(array[0]);

    int maxi = INT_MIN;
    int mini = INT_MAX;

    getMaximum(array,size,maxi);
    getMinimun(array,size,mini);

    cout<<"maxi="<<maxi<<endl;
    cout<<"mini="<<mini<<endl;

    return 0;
}